#include "stdafx.h"
#include "Icosahedron.h"

CIcosahedron::CIcosahedron(CMatrix4d const& transform)
	:m_mash(nullptr)
{
	double radius = 1;

	double magicAngle = M_PI * 26.565f / 180;
	double segmentAngle = M_PI * 72 / 180;
	double currentAngle = 0.0f;

	std::vector<Vertex> vertices(12);
	vertices[0] = CVector3d(0, radius, 0);
	vertices[11] = CVector3d(0, -radius, 0);

	for (int i = 1; i < 6; i++)
	{
		vertices[i] = CVector3d(radius * std::sin(currentAngle) * std::cos(magicAngle),
			radius * std::sin(magicAngle),
			radius * std::cos(currentAngle) * std::cos(magicAngle));
		currentAngle += segmentAngle;
	}
	currentAngle = M_PI * 36 / 180;
	for (int i = 6; i < 11; i++)
	{
		vertices[i] = CVector3d(radius * std::sin(currentAngle) * std::cos(-magicAngle),
			radius * std::sin(-magicAngle),
			radius * std::cos(currentAngle) * std::cos(-magicAngle));
		currentAngle += segmentAngle;
	}

	std::vector<Face> faces{
		{ 0, 1, 2},
		{ 0, 2, 3},
		{ 0, 3, 4},
		{ 0, 4, 5},
		{ 0, 5, 1},
		{ 11, 7, 6},
		{ 11, 8, 7 },
		{ 11, 9, 8 },
		{ 11, 10, 9 },
		{ 11, 6, 10 },
		{ 2, 1, 6 },
		{ 3, 2, 7 },
		{ 4, 3, 8 },
		{ 5, 4, 9 },
		{ 1, 5, 10 },
		{ 6, 7, 2 },
		{ 7, 8, 3 },
		{ 8, 9, 4 },
		{ 9, 10, 5 },
		{ 10, 6, 1 },
	};

	// Данные полигональной сетки
	std::shared_ptr<CTriangleMeshData> pMeshData = std::make_shared<CTriangleMeshData>(vertices, faces);

	m_mash = CTriangleMesh(pMeshData, transform);
}

bool CIcosahedron::Hit(CRay const& ray, CIntersection& intersection) const
{
	return m_mash.Hit(ray, intersection);
}
