#pragma once
#define _USE_MATH_DEFINES 
#include <GLFW/glfw3.h>
#include <math.h>

class KroshPicture {
public:
	KroshPicture(float x, float y): m_x(x), m_y(y) {}
	void Draw()const
	{
		glClear(GL_COLOR_BUFFER_BIT);

		DrawHead();

		DrawHands();
		DrawLegs();
		DrawEars();
	}
private:
	void DrawHead()const
	{
		glColor3f(0.25f, 0.80f, 0.89f);
		FillEllipse(m_x, m_y, 100, 100);

		DrawEye(m_x - 30, m_y - 30);
		DrawEye(m_x + 30, m_y - 30);

		// Draw Nose
		glColor3f(0.9f, 0.25f, 0.9f);
		glPointSize(15);
		glBegin(GL_POINTS);
		glVertex2f(m_x, m_y);
		glEnd();

		//Draw mouth
		glColor3f(0, 0, 0);
		glBegin(GL_TRIANGLE_STRIP);
		{
			glVertex2f(m_x - 30, m_y + 30);
			glVertex2f(m_x + 30, m_y + 30);
			glVertex2f(m_x, m_y + 60);
		}
		glEnd();

		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
		{
			glVertex2f(m_x - 15, m_y + 30);
			glVertex2f(m_x - 5, m_y + 30);
			glVertex2f(m_x - 5, m_y + 40);
			glVertex2f(m_x - 15, m_y + 40);
		}
		glEnd();

		glBegin(GL_POLYGON);
		{
			glVertex2f(m_x, m_y + 30);
			glVertex2f(m_x + 10, m_y + 30);
			glVertex2f(m_x + 10, m_y + 50);
			glVertex2f(m_x, m_y + 50);
		}
		glEnd();
	}

	void DrawHands()const
	{
		glColor3f(0.25f, 0.80f, 0.89f);
		FillEllipse(m_x - 115, m_y + 50, 20, 40);
		FillEllipse(m_x + 115, m_y + 50, 20, 40);
	}

	void DrawLegs()const
	{
		glColor3f(0.25f, 0.80f, 0.89f);
		FillEllipse(m_x - 30, m_y + 110, 30, 20);
		FillEllipse(m_x + 30, m_y + 110, 30, 20);
	}

	void DrawEars()const
	{
		glColor3f(0.25f, 0.80f, 0.89f);
		FillEllipse(m_x - 50, m_y - 150, 30, 100, M_PI / 2);
		FillEllipse(m_x + 50, m_y - 150, 30, 100, M_PI / 2);
	}

	static void DrawEye(float x, float y)
	{
		glColor3f(1, 1, 1);
		FillEllipse(x, y, 15, 30);

		glPointSize(10);
		glEnable(GL_POINT_SMOOTH);
		glBegin(GL_POINTS);
		glColor3f(0, 0, 0);
		glVertex2f(x, y);
		glEnd();
	}

	static void FillEllipse(float xCenter, float yCenter, float rx, float ry, float rotateAngle = 0, int points = 360)
	{
		const float step = static_cast<float>(2 * M_PI / points);

		glBegin(GL_TRIANGLE_FAN);
		glVertex2d(xCenter, yCenter);
		for (float angle = 0; angle <= 2 * M_PI; angle += step)
		{
			float a = (fabsf(static_cast<float>(angle - 2 * M_PI)) < 1e-5) ? 0 : angle;
			const float dx = rx * cosf(a + rotateAngle);
			const float dy = ry * sinf(a + rotateAngle);
			glVertex2f(dx + xCenter, dy + yCenter);
		}
		glEnd();
	}

	float m_x;
	float m_y;
};