#include "Window.h"
#include "GLFWInitializer.h"

int main()
{
	GLFWInitializer initGLFW;
	Window window{ 800, 600, "Krosh" };
	window.Run();
}