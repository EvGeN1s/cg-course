#include "pch.h"
#include "CCircle.h"
#include <cmath>
#include <iostream>

void CCircle::Draw()
{
	float y = 1.0f;
	float step = M_PI / 100;

	glPointSize(1.0f);
	glBegin(GL_LINE_LOOP);

	for (float x = 0; x < 4 * M_PI; x += step)
	{
		glVertex2f(x, y);
	}
	glEnd();
}