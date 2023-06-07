#include "CRotationController.h"

CRotationController::CRotationController(int windowWidth, int windowHeight)
	:m_leftButtonPressed(false)
	, m_windowWidth(windowWidth)
	, m_windowHeight(windowHeight)
{
}

CRotationController::~CRotationController(void)
{
}

void CRotationController::ResizeWindow(int windowWidth, int windowHeight)
{
	m_windowWidth = windowWidth;
	m_windowHeight = windowHeight;
}

void CRotationController::OnMouse(int button, int state, int x, int y)
{
	// ������� �� ����� ������ ����
	if (button == GLUT_LEFT_BUTTON)
	{
		// ��������� ��������� ����� ������ ����
		m_leftButtonPressed = (state == GLUT_DOWN);
		// ��������� ���������� ����
		m_mouseX = x;
		m_mouseY = y;
	}
}

void CRotationController::OnMotion(int x, int y)
{
	// ���� ������ ����� ������ ����
	if (m_leftButtonPressed)
	{
		// ��������� �������� ������� ����
		int dx = x - m_mouseX;
		int dy = y - m_mouseY;

		// ��������� ���� �������� ������ ���� Y � X ��� ������� ���������
		// �� �������� ���� �� ���� X � Y
		GLfloat rotateX = GLfloat(dy) * 180 / m_windowHeight;
		GLfloat rotateY = GLfloat(dx) * 180 / m_windowWidth;

		RotateCamera(rotateX, rotateY);

		// ��������� ������� ���������� ����
		m_mouseX = x;
		m_mouseY = y;
	}
}


// ������� ������ ������ ������ �������� �� �������� ����
void CRotationController::RotateCamera(GLfloat rotateX, GLfloat rotateY)
{
	// ��������� ������� �������� ������� �������������-����
	GLfloat modelView[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, &modelView[0]);

	// ��������� ����������� ������������ ���� ������ � 3� ������������
	// ��� ������������ ����� ������� �������������-����
	glm::vec3 xAxis(modelView[0], modelView[4], modelView[8]);
	glm::vec3 yAxis(modelView[1], modelView[5], modelView[9]);

	// ������������ ������ ���� x � y ������
	glRotatef(rotateX, xAxis.x, xAxis.y, xAxis.z);
	glRotatef(rotateY, yAxis.x, yAxis.y, yAxis.z);

	// � ���� ��������� ������ ����� ��������� �����������, �������,
	// ������������ ����� ������ �������� ��������
	// ��� �� ����������� ����� ������ ����������� ������� �������������-����
	// �������� �� ����������������
	NormalizeModelViewMatrix();
}

// ���������� ���������������� ������� �������������-����
void CRotationController::NormalizeModelViewMatrix(void)
{
	GLfloat modelView[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, modelView);

	/*
	���������������� - ���������� ������������ ���� �
	��������� ����� (������������)
	� �������� ������������������ (���������������)
	������� ����� ����� ��� ������ ������������ ������������ ����
	� ���������� ������������
	*/
	glm::vec3 xAxis(modelView[0], modelView[4], modelView[8]);
	xAxis = glm::normalize(xAxis);
	glm::vec3 yAxis(modelView[1], modelView[5], modelView[9]);
	yAxis = glm::normalize(yAxis);

	// ��� Z ��������� ����� ��������� ������������ X � Y
	// Z ����� ��������������� ��������� �������� X � Y
	glm::vec3 zAxis = glm::cross(xAxis, yAxis);
	// � ����� ��������� �����
	zAxis = glm::normalize(zAxis);
	// �� �� ����� ����������� � ����� x � y
	xAxis = glm::cross(yAxis, zAxis);
	xAxis = glm::normalize(xAxis);
	yAxis = glm::cross(zAxis, xAxis);
	yAxis = glm::normalize(yAxis);

	// ��������� ������� ������������ ���� ������� � ������
	modelView[0] = xAxis.x; modelView[4] = xAxis.y, modelView[8] = xAxis.z;
	modelView[1] = yAxis.x; modelView[5] = yAxis.y, modelView[9] = yAxis.z;
	modelView[2] = zAxis.x; modelView[6] = zAxis.y, modelView[10] = zAxis.z;

	// � ��������� ������� ������������-����
	glLoadMatrixf(modelView);
}

bool CRotationController::LeftButtonIsPressed()const
{
	return m_leftButtonPressed;
}