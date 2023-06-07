#pragma once
#include "Shader.h"
#include "CGLapplication.h"
#include "CMorphShape.h"
#include "CAnimationController.h"



class CMyApplication : public CGLApplication
{
public:
	CMyApplication(const char* title, int width, int height, int argc, char* argv[]);
	~CMyApplication() = default;

protected:
	virtual void OnDisplay();
	virtual void OnInit();
	virtual void OnReshape(int width, int height);
	virtual void OnIdle();
private:
	void InitShaders();

private:
	// ���������� ������ � ������
	static const int NUMBER_OF_VERTICES;
	// ������������ �������
	static const float SHAPE_MAX_RADIUS;
	// ����������� ������
	static const float SHAPE_MIN_RADIUS;
	// ������ ������ �������� ��������
	static const float ANIMATION_PERIOD;

	static const double FIELD_OF_VIEW;

	static const double Z_NEAR;
	static const double Z_FAR;


	CAnimationController m_animationController;

	// ���������������� ������
	CMorphShape m_morphShape;

	float m_phase;
	int m_phaseDirection = 1;

	CProgram m_program;
};