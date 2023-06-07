#include "pch.h"
#include "Window.h"
#include "Cube.h"
#include "TextureLoader.h"
#include <string>

#include "CDirectLight.h"

namespace
{
	// ���� ������ �� ���������
	constexpr double FIELD_OF_VIEW = 60 * M_PI / 180.0;
	// ������ ������� ����
	constexpr double CUBE_SIZE = 1;

	constexpr double Z_NEAR = 0.2;
	constexpr double Z_FAR = 20;

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

namespace
{
	std::shared_ptr<Cube> CreateCube(float size)
	{
		auto cube = std::make_shared<Cube>(size);
		cube->SetSpecularColor({ 1, 1, 1, 1 });
		cube->SetShininess(4.0f);

		return cube;
	}

	std::shared_ptr<CPyramid> CreatePyramid(CPyramid::PyramidSideSize&& size, float height)
	{
		auto pyramid = std::make_shared<CPyramid>(std::move(size), height);
		pyramid->SetSpecularColor({ 1, 1, 1, 1 });
		pyramid->SetShininess(4.0f);

		return pyramid;
	}
} // namespace

Window::Window(int w, int h, const char* title)
	: BaseWindow(w, h, title),
	m_skyBox(L"./texture/land_texture.jpg"),
	m_rotationController(w, h),
	m_polygonMode(GL_FILL)
{}

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
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// �������� ����� ���������� ������
	glEnable(GL_CULL_FACE);
	// ��������������� ����� ��������� ������� ������
	glCullFace(GL_BACK);
	// ������� ��������� ��������� �������, ���� ��� �� ���������
	// ����� ������ �������������� ������ ������� �������
	glFrontFace(GL_CCW);

	// �������� ���� ������� ��� �������� ��������� ����� � ������������
	glEnable(GL_DEPTH_TEST);

	// ����������� �� �������� ����� (��������� � �������� �����������)
	CDirectLight light{ { 0.0f, 0.0f, 1.0f } };
	light.SetDiffuseIntensity({ 0.5f, 0.5f, 0.5f, 1.0f });
	light.SetAmbientIntensity({ 0.0f, 0.0f, 0.0f, 1.0f });
	light.SetSpecularIntensity({ 0.3f, 0.3f, 0.3f, 1.0f });
	light.Apply(GL_LIGHT0);
}



#ifndef GL_CLAMP_TO_EDGE_EXT
#define GL_CLAMP_TO_EDGE_EXT 0x812F
#endif

void Window::Draw(int width, int height)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// �������� ����� ��������� ��������
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	glPolygonMode(GL_FRONT_AND_BACK, m_polygonMode);

	SetupCameraMatrix();

	DrawSkyBox();
	DrawScene();
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

void Window::DrawSkyBox()const
{
	glDisable(GL_LIGHTING);
	// �������� ����� ���������� ������, �.�. 
	// �� ��������� ������ ���� � ����� ��� ��������� �������
	glDisable(GL_CULL_FACE);

	m_skyBox.Draw();
}

void Window::DrawScene() const
{
	m_house.Draw();
	m_land.Draw();
}
