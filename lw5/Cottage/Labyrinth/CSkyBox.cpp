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
����� ������������ ���������� ���������, ��� �������
��� ������ ���������� ���������� ��������� �� ������� ��������� 0-1,
������������ �������� ������� �� ��������� ����� ����������� �����������.
������ ����� ����������� � ������������ ������ OpenGL 1.1, ������������ �
Visual Studio, �� �������� � ���� ���������� � �������������� �
��������� ����� ����� ������������ ������������
*/
#ifndef GL_CLAMP_TO_EDGE_EXT
#define GL_CLAMP_TO_EDGE_EXT 0x812F
#endif

void CSkyBox::Draw()const
{
	// ������������� ����������� ������ ������������ ����
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_DEPTH_TEST);
	glDepthMask(GL_FALSE);

	// ��������� ������� �������
	glPushMatrix();

	// ��������� ������ ������������� � 4 ������� ������� (�������� 12-14)
	// ���� ������� ���� 0, �� ������� ������ �������� ��������.
	GLfloat modelView[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, modelView);
	modelView[12] = modelView[13] = modelView[14] = 0;
	glLoadMatrixf(modelView);

	auto texture = m_textureProvider.GetTexture(TextureName::SKY_TEXTURE);
	texture->Bind();

	// ������ ���
	m_cube.Draw();

	// ��������������� ������� �������
	glPopMatrix();

	glDepthMask(GL_TRUE);
	glEnable(GL_DEPTH_TEST);
}
