#include "CSkyBox.h"
#include "pch.h"
#include "TextureLoader.h"

CSkyBox::CSkyBox(
	std::wstring const& texture
)
	:m_initialized(false)
	, m_texture(texture)
	, m_cube(5)
{
}

/*
Режим оборачивания текстурных координат, при котором
при выходе текстурной координаты фрагмента за пределы диапазона 0-1,
используется значение пикселя на ближайшем ребре текстурного изображения.
Данные режим отсутствует в заголовочных файлах OpenGL 1.1, поставляемых с
Visual Studio, но доступен в виде расширения и поддерживается в
настоящее время всеми современными видеокартами
*/
#ifndef GL_CLAMP_TO_EDGE_EXT
#define GL_CLAMP_TO_EDGE_EXT 0x812F
#endif

void CSkyBox::Draw()const
{
	// Устанавливаем необходимые режимы визуализации куба
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_DEPTH_TEST);
	glDepthMask(GL_FALSE);

	// сохраняем текущую матрицу
	glPushMatrix();

	// Положение камеры располаагется в 4 столбце матрицы (элементы 12-14)
	// Если занести туда 0, то матрица станет матрицей вращения.
	GLfloat modelView[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, modelView);
	modelView[12] = modelView[13] = modelView[14] = 0;
	glLoadMatrixf(modelView);

	auto texture = m_textureProvider.GetTexture(TextureName::SKY_TEXTURE);
	texture->Bind();

	// рисуем куб
	m_cube.Draw();

	// восстанавливаем текущую матрицу
	glPopMatrix();

	glDepthMask(GL_TRUE);
	glEnable(GL_DEPTH_TEST);
}
