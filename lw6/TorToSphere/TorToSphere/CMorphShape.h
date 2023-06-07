#include "pch.h"
#include "Buffer.h"
#include "Shader.h"

struct Vertex
{
	glm::vec3 startPos;
	glm::vec3 endPos;
};

class CMorphShape
{
public:
	CMorphShape(size_t numberOfVertices, float maxRadius, float minRadius);

	// �������� ������ � ��������� � ������������ �� ����������
	void SetProgram(
		GLuint program, GLuint phaseLocation, GLuint endPosLocation);

	// ������ ����
	void Draw(float phase)const;
private:
	// ������������� ������
	void Create()const;

	// ���������� ������ � ������
	size_t const m_numberOfVertices;

	// ����������� � ������������ ������ ���������
	float const m_maxRadius;
	float const m_minRadius;

	// ��������� ����� � ��������� �� ����������� � ��� �������
	mutable bool m_initialized;
	mutable CVertexBuffer m_vertexBuffer;
	mutable GLubyte const* m_pStartPosArray;
	mutable GLubyte const* m_pEndPosArray;

	CProgramHandle m_program;
	GLuint m_phaseLocation;
	GLuint m_endPosLocation;
};
