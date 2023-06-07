#include "pch.h"
#include "CCircle.h"
#include <cmath>
#include <iostream>

float starRadius(float x)
{

	const int n = 8;
	const int m = 6;
	const float k = 0.7;
	const float limit = 0.01;


	float topSin = asin(k);
	if (topSin == 0) 
	{
		topSin = limit;
	}
	float botSin = asin(k * cos(n * x));
	if (botSin == 0)
	{
		botSin = limit;
	}

	float top = cos((2 * topSin + M_PI * m) / (2 * n));
	float bot = cos((2 * botSin + M_PI * m) / (2 * n));


	if (bot == 0) 
	{
		bot = limit;
	}

	float r = top / bot;

	return abs(r);
}

void CCircle::Draw()
{
	float y = 1.0f;
	float z = 1.0f;
	float step = M_PI / 100;

	glPointSize(1.0f);
	glBegin(GL_LINE_LOOP);	

	for (float x = 0; x < 4 * M_PI; x += step)
	{
			
		
		glVertex2f(x, y);
	}
	glEnd();
}