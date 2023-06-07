#include "KleinBottle.h"
#include "pch.h"

// Масштабировать матрицей моделиования вида
// Подобрать цвета
KleinBottle::KleinBottle(double radius)
	:m_radius(radius)
{
	m_scale = radius;
}

void KleinBottle::Draw(void) const
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glScalef(m_radius * 0.2f, m_radius * 0.2f, m_radius * 0.2f);

	DrawTopSide();
	DrawBottomSide();

	glFlush();
}

void KleinBottle::DrawTopSide() const
{
	for (double u = 0; u < (M_PI)+0.05; u += 0.05)
	{
		glBegin(GL_TRIANGLE_FAN);

		for (double v = 0; v <= 2 * M_PI; v += 0.05)
		{
			DrawTopSidePart(u, v);
		}

		glEnd();
	}
}

void KleinBottle::DrawBottomSide() const
{
	for (double u = (M_PI)+0.05; u < 2 * (M_PI)+0.05; u += 0.05)
	{
		glBegin(GL_TRIANGLE_FAN);

		for (double v = 0; v <= 2 * M_PI; v += 0.05)
		{
			DrawBottomSidePart(u, v);
		}

		glEnd();
	}
}

void KleinBottle::DrawTopSidePart(double u, double v) const
{
	double x = 6 * cos(u) * (1 + sin(u)) + 4 * m_radius * (1 - (cos(u) / 2)) * cos(u) * cos(v);
	double y = 16 * sin(u) + 4 * m_radius * (1 - (cos(u) / 2)) * sin(u) * cos(v);
	double z = 4 * m_radius * (1 - (cos(u) / 2)) * sin(v);

	glColor3f(abs(cos(u) + sin(u)) /2 , abs(cos(u) - sin(v)) / 2, abs(sin(u) + cos(v)) / 2);
	glVertex3f(x, y, z);
}

void KleinBottle::DrawBottomSidePart(double u, double v) const
{
	double x = 6 * cos(u) * (1 + sin(u)) - 4 * m_radius * (1 - (cos(u) / 2)) * cos(v);
	double y = 16 * sin(u);
	double z = 4 * m_radius * (1 - (cos(u) / 2)) * sin(v);

	glColor3f(abs(cos(u) + sin(u)) / 2, abs(cos(u) - sin(v)) / 2, abs(sin(u) + cos(v)) / 2);
	glVertex3f(x, y, z);
}