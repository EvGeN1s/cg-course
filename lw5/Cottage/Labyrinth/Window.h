#pragma once
#include "BaseWindow.h"
#include "CRotationController.h"
#include "Texture.h"
#include "CSkyBox.h"
#include "CLight.h"
#include "CHouse.h"
#include "Land.h"

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

	void DrawSkyBox()const;
	void DrawScene()const;

	// Режим визуализации граней
	// (переключается при помощи клавиши Пробел)
	GLenum m_polygonMode;

	static constexpr double DISTANCE_TO_ORIGIN = 5;

	mutable CTexture2D m_texture;

	bool m_leftButtonPressed = false;
	glm::dvec2 m_mousePos = {};
	glm::dmat4x4 m_cameraMatrix = glm::lookAt(
		glm::dvec3{ 5.0, 4.0, DISTANCE_TO_ORIGIN },
		glm::dvec3{ 0.0, 0.0, 0.0 },
		glm::dvec3{ 0.0, 1.0, 0.0 });
	
	CSkyBox m_skyBox;
	CHouse m_house;
	Land m_land;

	CRotationController m_rotationController;
};