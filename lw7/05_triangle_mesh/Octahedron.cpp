#include "stdafx.h"
#include "Octahedron.h"
#include "stdafx.h"
#include "Icosahedron.h"

COctahedron::COctahedron(CMatrix4d const& transform)
	: m_mash(nullptr)
{
	double radius = 1;

	std::vector<Vertex> vertices = {
		Vertex({0, -radius, 0}),
		Vertex({-radius, 0, 0}),
		Vertex({0, 0, -radius}),
		Vertex({+radius, 0, 0}),
		Vertex({0, 0, +radius}),
		Vertex({0, radius, 0})
	};

	std::vector<Face> faces = {
		{0, 1, 2},
		{0, 2, 3},
		{0, 3, 4},
		{0, 4, 1},
		{5, 2, 1},
		{5, 3, 2},
		{5, 4, 3},
		{5, 1, 4},
	};

	// Данные полигональной сетки
	std::shared_ptr<CTriangleMeshData> pMeshData = std::make_shared<CTriangleMeshData>(vertices, faces);

	m_mash = CTriangleMesh(pMeshData, transform);
}

bool COctahedron::Hit(CRay const& ray, CIntersection& intersection) const
{
	return m_mash.Hit(ray, intersection);
}
