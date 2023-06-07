#include "GLWFIntitalizer.h"
#include "Window.h"

int main(int argc, char* argv) 
{
	GLFWInitializer initGLFW;
	Window window{ 800, 600, "Klein bottle" };
	window.Run();
}