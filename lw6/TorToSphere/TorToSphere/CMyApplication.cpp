#include "pch.h"
#include "CMyApplication.h"
#include "ProgramLinker.h"
#include "ShaderCompiler.h"
#include "ShaderLoader.h"
#include "Scene.h"

const int CMyApplication::NUMBER_OF_VERTICES = 360;

const float CMyApplication::SHAPE_MAX_RADIUS = 1.2f;
const float CMyApplication::SHAPE_MIN_RADIUS = 0.4f;

const float CMyApplication::ANIMATION_PERIOD = 3.0f;

const double CMyApplication::FIELD_OF_VIEW = 60;
const double CMyApplication::Z_NEAR = 0.1;
const double CMyApplication::Z_FAR = 10;



CMyApplication::CMyApplication(const char* title, int width, int height, int argc, char* argv[])
	: CGLApplication(title, argc, argv, width, height)
	,m_morphShape(NUMBER_OF_VERTICES, SHAPE_MAX_RADIUS, SHAPE_MIN_RADIUS)
	, m_phase(0)
{
}

void CMyApplication::OnInit()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(1, 1, 1, 1);
	glColor3f(0, 0, 0);


	gluLookAt(
		1, 1, 1,
		0, 0, 0,
		0, 1, 0
	);

	//glLoadIdentity();

	InitShaders();
}


void CMyApplication::InitShaders()
{
	if (!GLEW_EXT_geometry_shader4)
	{
		throw std::runtime_error("The OpenGL implementation does not support geometry shaders");
	}

	ShaderLoader loader;
	CShader vertexShader =
		loader.LoadShader(GL_VERTEX_SHADER, L"vertex_blend.vsh");

	ShaderCompiler compiler;
	compiler.CompileShader(vertexShader);
	compiler.CheckStatus();

	m_program.Create();
	m_program.AttachShader(vertexShader);	

	ProgramLinker linker;
	linker.LinkProgram(m_program);
	linker.CheckStatus();
}

void CMyApplication::OnDisplay()
{

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(m_program);
	glUniform1f(m_program.GetUniformLocation("phase"), m_phase);
	glUniform1f(m_program.GetUniformLocation("radius"), SHAPE_MAX_RADIUS);
	glUniform1f(m_program.GetUniformLocation("smallRadius"), SHAPE_MIN_RADIUS);

	glPushMatrix();
	glScalef(0.5f, 0.5f, 0.5f);
	Scene::Draw();
	glPopMatrix();

	glUseProgram(0);
}

void CMyApplication::OnReshape(int width, int height)
{
	glViewport(0, 0, width, height);

	// Вычисляем соотношение сторон клиентской области окна
	double aspect = double(width) / double(height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(
		-SHAPE_MAX_RADIUS * aspect, SHAPE_MAX_RADIUS * aspect,
		-SHAPE_MAX_RADIUS, SHAPE_MAX_RADIUS,
		-1, +1);
	gluPerspective(FIELD_OF_VIEW, aspect, Z_NEAR, Z_FAR);
	glMatrixMode(GL_MODELVIEW);

}

void CMyApplication::OnIdle()
{
	m_animationController.Tick();

	float delta = m_animationController.GetTimeDelta() * 0.0005f;
	if ((m_phase > 1) || (m_phase < 0)) {
		m_phaseDirection= -m_phaseDirection;
	}
	m_phase = float(m_phase + delta * m_phaseDirection / ANIMATION_PERIOD);

	PostRedisplay();

}
