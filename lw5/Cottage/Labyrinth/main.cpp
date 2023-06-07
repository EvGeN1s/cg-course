#include "GLFWInitializer.h"
#include "CGdiplusInitializer.h"
#include "Window.h"

int main(int argc, char* argv)
{
	GLFWInitializer initGLFW;
	CGdiplusInitializer initGdiplus;
	Window window{ 800, 600, "Cottage" };
	window.Run();
}