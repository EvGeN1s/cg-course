#pragma once
#include "BaseWindow.h"
#include "KroshPicture.h"
#include "GLFW/glfw3.h"

class Window : public BaseWindow
{
public:
	using BaseWindow::BaseWindow;
private:
	void Draw(int width, int height) override
	{
		glViewport(0, 0, width, height);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, width, height, 0, -1, 1);
		glMatrixMode(GL_MODELVIEW);

		KroshPicture picture(width / 2, height / 2);
		picture.Draw();
	}
};
