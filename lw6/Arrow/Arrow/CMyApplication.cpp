#include "pch.h"
#include "CMyApplication.h"
#include "ProgramLinker.h"
#include "ShaderCompiler.h"
#include "ShaderLoader.h"

CMyApplication::CMyApplication(const char* title, int width, int height, int argc, char* argv[])
	: CGLApplication(title, argc, argv, width, height)
{
}

void CMyApplication::OnInit()
{
	InitShaders();
}

void CMyApplication::InitShaders()
{
	if (!GLEW_EXT_geometry_shader4)
	{
		throw std::runtime_error("The OpenGL implementation does not support geometry shaders");
	}

	ShaderLoader loader;
	CShader geometryShader = loader.LoadShader(GL_GEOMETRY_SHADER, L"geometry_shader.gsh");
	CShader vertexShader = loader.LoadShader(GL_VERTEX_SHADER, L"vertex_shader.vsh");
	CShader fragmentShader = loader.LoadShader(GL_FRAGMENT_SHADER, L"fragment_shader.fsh");


	ShaderCompiler compiler;
	compiler.CompileShader(vertexShader);
	compiler.CompileShader(geometryShader);
	compiler.CompileShader(fragmentShader);
	compiler.CheckStatus();

	m_program.Create();	
	m_program.AttachShader(vertexShader);
	m_program.AttachShader(geometryShader);
	m_program.AttachShader(fragmentShader);

	// Задаем параметры шейдерной программы
   // тип входных примитивов: точки
	m_program.SetParameter(GL_GEOMETRY_INPUT_TYPE_ARB, GL_POINTS);
	// типв выходных примитивов: лента из треугольникков
	m_program.SetParameter(GL_GEOMETRY_OUTPUT_TYPE_ARB, GL_LINE_STRIP);
	// Максимальное количество вершин, порождаемых геометрическим шейдером
	// за один вызов. Для ленты из двух треугольников оно равно 4
	m_program.SetParameter(GL_GEOMETRY_VERTICES_OUT_EXT, 33);


	ProgramLinker linker;
	linker.LinkProgram(m_program);
	linker.CheckStatus();
}

void CMyApplication::OnDisplay()
{
	glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(m_program);

	glUniform1f(m_program.GetUniformLocation("Size"), 0.3f);

	glBegin(GL_POINTS);
	{
		glVertex2f(-0.5, -0.5);
		glVertex2f(0.5, 0.5);
	}
	glEnd();

	glPopMatrix();

	glUseProgram(0);
}

void CMyApplication::OnReshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	const auto aspectRatio = static_cast<float>(width) / static_cast<float>(height) * 0.7;
	gluOrtho2D(-aspectRatio, aspectRatio, -1.0f, 1.0f);

	glMatrixMode(GL_MODELVIEW);
}