#include "Dodecahedron.h"
#include <vector>
#include <iostream>

Dodecahedron::Dodecahedron(float size)
	: m_size(size)
{
	constexpr glm::vec4 defaultColor{ 1, 1, 1, 1 };
}
 
void Dodecahedron::Draw() const
{

	int faces[12][5] =
	{
		{0, 16, 2, 10, 8},
		{0, 8, 4, 14, 12},
		{16, 17, 1, 12, 0},
		{1, 9, 11, 3, 17},
		{1, 12, 14, 5, 9},
		{2, 13, 15, 6, 10},
		{13, 3, 17, 16, 2},
		{3, 11, 7, 15, 13},
		{4, 8, 10, 6, 18},
		{14, 5, 19, 18, 4},
		{5, 19, 7, 11, 9},
		{15, 7, 19, 18, 6}
	};
	double points[20][3] =
	{
		{1, 1, 1},
		{1, 1, -1},
		{1, -1, 1},
		{1, -1, -1},
		{-1, 1, 1},
		{-1, 1, -1},
		{-1, -1, 1},
		{-1, -1, -1},
		{0, 0.618, 1.618},
		{0, 0.618, -1.618},
		{0, -0.618, 1.618},
		{0, -0.618, -1.618},
		{0.618, 1.618, 0},
		{0.618, -1.618, 0},
		{-0.618, 1.618, 0},
		{-0.618, -1.618, 0},
		{1.618, 0, 0.618},
		{1.618, 0, -0.618},
		{-1.618, 0, 0.618},
		{-1.618, 0, -0.618}
	};

	static size_t const faceCount = sizeof(faces) / sizeof(*faces);

	glPushMatrix();
	//glScalef(m_size * 0.5f, m_size * 0.5f, m_size * 0.5f);

	glEnable(GL_COLOR_MATERIAL);
	// ÷вет вершины будет управл€ть диффузным и фоновым цветом материала
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, glm::value_ptr(m_specularColor));
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, m_shininess);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (int i = 0; i < 12; i++)
	{
		int colorStep = (i % 2 == 0) ? 1 : -1;
		glColor3f(0.5 + 0.2 * i * colorStep, 0.7 - 0.1 * i * colorStep, 0.4 - 0.05 * i * colorStep);
		glBegin(GL_TRIANGLE_FAN);
		for (int j = 0; j < 5; j++)
		{
			glVertex3dv(points[faces[i][j]]);
		}
		glEnd();
		
		glColor3f(0, 0, 0);
		glBegin(GL_LINE_LOOP);
		for (int j = 0; j < 5; j++)
		{
			glVertex3dv(points[faces[i][j]]);
		}		
		glEnd();
	}
	glFlush();

}


void Dodecahedron::SetSpecularColor(glm::vec4 color)
{
	m_specularColor = color;
}

void Dodecahedron::SetShininess(float shininess)
{
	m_shininess = shininess;
}