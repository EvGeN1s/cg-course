#include "pch.h"
#include "Window.h"
#include "DIrectLight.h"
#include "MobiusStrip.h"
#include "KleinBottle.h"

namespace
{
	// ���� ������ �� ���������
	constexpr double FIELD_OF_VIEW = 60 * M_PI / 180.0;
	// ������ ������� ����
	constexpr double CUBE_SIZE = 1;

	constexpr double Z_NEAR = 0.1;
	constexpr double Z_FAR = 10;

	// ������������� ������� 4*4 (��� ������ ���� �������� �������)
	glm::dmat4x4 Orthonormalize(const glm::dmat4x4& m)
	{
		// ��������� ���������� 3*3 �� ������� m � ������������� �
		const auto normalizedMatrix = glm::orthonormalize(glm::dmat3x3{ m });
		// �������� 3 ������� �������� �������
		return {
			glm::dvec4{ normalizedMatrix[0], 0.0 },
			glm::dvec4{ normalizedMatrix[1], 0.0 },
			glm::dvec4{ normalizedMatrix[2], 0.0 },
			m[3]
		};
	}

}

Window::Window(int w, int h, const char* title)
	: BaseWindow(w, h, title)
	, m_cube(CUBE_SIZE), m_dodecahedron(CUBE_SIZE)
{
	m_cube.SetSideColor(CubeSide::NEGATIVE_X, { 1, 0, 0, 1 });
	m_cube.SetSideColor(CubeSide::POSITIVE_X, { 0, 1, 0, 1 });
	m_cube.SetSideColor(CubeSide::NEGATIVE_Y, { 0, 0, 1, 1 });
	m_cube.SetSideColor(CubeSide::POSITIVE_Y, { 1, 1, 0, 1 });
	m_cube.SetSideColor(CubeSide::NEGATIVE_Z, { 0, 1, 1, 1 });
	m_cube.SetSideColor(CubeSide::POSITIVE_Z, { 1, 0, 1, 1 });

	m_cube.SetSpecularColor({ 1, 1, 1, 1 });
	m_cube.SetShininess(4.0f);

	m_dodecahedron.SetSpecularColor({ 1, 1, 1, 1 });
	m_dodecahedron.SetShininess(4.0f);
}

void Window::OnResize(int width, int height)
{
	glViewport(0, 0, width, height);

	// ��������� ����������� ������ ���������� ������� ����
	double aspect = double(width) / double(height);

	glMatrixMode(GL_PROJECTION);
	const auto proj = glm::perspective(FIELD_OF_VIEW, aspect, Z_NEAR, Z_FAR);
	glLoadMatrixd(&proj[0][0]);
	glMatrixMode(GL_MODELVIEW);
}

void Window::OnRunStart()
{
	glLineWidth(2);

	// �������� ���� ������� ��� �������� ��������� ����� � ������������
	glEnable(GL_DEPTH_TEST);

	// ����������� �� �������� ����� (��������� � �������� �����������)
	//DirectLight light{ { 0.0f, 0.0f, 1.0f } };
	//light.SetDiffuseIntensity({ 0.5f, 0.5f, 0.5f, 1.0f });
	//light.SetAmbientIntensity({ 0.0f, 0.0f, 0.0f, 1.0f });
	//light.SetSpecularIntensity({ 0.3f, 0.3f, 0.3f, 1.0f });
	//light.Apply(GL_LIGHT0);
}

void Window::Draw(int width, int height)
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	SetupCameraMatrix();

	m_dodecahedron.Draw();

	//KleinBottle bottle(1);
	//bottle.Draw();
}

void Window::RotateCamera(double xAngleRadians, double yAngleRadians)
{
	// ��������� �� 1 � 2 ������ ������� ������ ����������� ���� ��������,
	// ����������� � ��������� ����� X � Y.
	// ������ ������, ��� ����� ���� ��������� ������� �� �������� ������� ������, �� ��� ���
	// ������� ������ �����������������, ���������� ��������������� � ���������� 3*3
	const glm::dvec3 xAxis{
		m_cameraMatrix[0][0], m_cameraMatrix[1][0], m_cameraMatrix[2][0]
	};
	const glm::dvec3 yAxis{
		m_cameraMatrix[0][1], m_cameraMatrix[1][1], m_cameraMatrix[2][1]
	};
	m_cameraMatrix = glm::rotate(m_cameraMatrix, xAngleRadians, xAxis);
	m_cameraMatrix = glm::rotate(m_cameraMatrix, yAngleRadians, yAxis);

	m_cameraMatrix = Orthonormalize(m_cameraMatrix);
}

void Window::OnMouseButton(int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_1)
	{
		m_leftButtonPressed = (action & GLFW_PRESS) != 0;
	}
}

void Window::OnMouseMove(double x, double y)
{
	const glm::dvec2 mousePos{ x, y };
	if (m_leftButtonPressed)
	{
		const auto windowSize = GetFramebufferSize();

		const auto mouseDelta = mousePos - m_mousePos;
		const double xAngle = mouseDelta.y * M_PI / windowSize.y;
		const double yAngle = mouseDelta.x * M_PI / windowSize.x;
		RotateCamera(xAngle, yAngle);
	}
	m_mousePos = mousePos;
}

void Window::SetupCameraMatrix()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd(&m_cameraMatrix[0][0]);
}

void Window::SetupProjectionMatrix(int width, int height)
{
	glViewport(0, 0, width, height);

	// ��������� ����������� ������ ���������� ������� ����
	double aspect = double(width) / double(height);

	glMatrixMode(GL_PROJECTION);
	const auto projMat = glm::perspective(60.0 * M_PI / 180.0, aspect, 0.1, 10.0);
	glLoadMatrixd(&projMat[0][0]);
}