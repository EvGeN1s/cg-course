#include "stdafx.h"
#include "Tetrahedron.h"


CTetrahedron::CTetrahedron(CMatrix4d const& transform)
	:m_mash(nullptr)
{
	// Вершины
	CVector3d v0(-1, 0, 1);
	CVector3d v1(+1, 0, 1);
	CVector3d v2(0, 0, -1);
	CVector3d v3(0, 2, 0);
	std::vector<Vertex> vertices;
	vertices.push_back(Vertex(v0));
	vertices.push_back(Vertex(v1));
	vertices.push_back(Vertex(v2));
	vertices.push_back(Vertex(v3));

	// Грани
	std::vector<Face> faces;
	faces.push_back(Face(0, 2, 1));
	faces.push_back(Face(3, 0, 1));
	faces.push_back(Face(3, 1, 2));
	faces.push_back(Face(3, 2, 0));

	// Данные полигональной сетки
	std::shared_ptr<CTriangleMeshData> pMeshData = std::make_shared<CTriangleMeshData>(vertices, faces);

	m_mash = CTriangleMesh(pMeshData, transform);
}

bool CTetrahedron::Hit(CRay const& ray, CIntersection& intersection) const
{
	return m_mash.Hit(ray, intersection);
}
