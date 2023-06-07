#include "pch.h"
#include "Scene.h"

void Scene::Draw()
{
	float x = 0, y = 0, z = 0;

	float u = 0, v = 0;
	float step = M_PI / 100;

	glBegin(GL_LINES);
	for (v = 0; v < 2 * M_PI; v += step)
	{
		for (u = 0; u <= 2 * M_PI; u += step)
		{
			glVertex3f(u, v, z);
			glColor3f(0, 0, 1);
		}
	}
	glEnd();
	//glBegin(GL_TRIANGLE_STRIP);
	//for (u = 0; u <= 1; u += 0.01)
	//{
	//	for (v = 0; v < 1 + 0.01; v += 0.01)
	//	{
	//		glVertex3f(u, v, z);
	//		glColor3f(u, v, z);
	//	}
	//}
	//glEnd();
	glFlush();
}