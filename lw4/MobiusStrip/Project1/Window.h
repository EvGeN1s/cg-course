#pragma once
#include "BaseWindow.h"
#include "Cube.h"
#include "Dodecahedron.h"

class Window : public BaseWindow
{
public:
	Window(int w, int h, const char* title);

private:
	void OnResize(int width, int height) override;

	void OnRunStart() override;

	void Draw(int width, int height) override;

	void RotateCamera(double xAngleRadians, double yAngleRadians);

	void OnMouseButton(int button, int action, int mods) override;
	void OnMouseMove(double x, double y) override;

	void SetupCameraMatrix();

	static void SetupProjectionMatrix(int width, int height);

	Cube m_cube;
	Dodecahedron m_dodecahedron;
	static constexpr double DISTANCE_TO_ORIGIN = 7.5;

	bool m_leftButtonPressed = false;
	glm::dvec2 m_mousePos = {};
	glm::dmat4x4 m_cameraMatrix = glm::lookAt(
		glm::dvec3{ 0.0, 0.0, DISTANCE_TO_ORIGIN },
		glm::dvec3{ 0.0, 0.0, 0.0 },
		glm::dvec3{ 0.0, 1.0, 0.0 });
};