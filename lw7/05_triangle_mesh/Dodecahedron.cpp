#include "stdafx.h"
#include "Dodecahedron.h"

CDodecahedron::CDodecahedron(CMatrix4d const& transform) 
	:m_mash(nullptr)
{
	std::vector<Face> faces{
		{0, 2, 16},	{0, 10, 2},	{0, 8, 10}, // face1
		// face2
		{0, 4, 8}, {0, 14, 4}, {0, 12, 14},
		//face3
		{16, 17, 1}, {16, 1, 12}, {16, 12, 0},
		//face4
		{1, 11, 9}, {1, 3, 11}, {1, 17, 3},
		//face5
		{1, 14, 12}, {1, 5, 14}, {1, 9, 5},
		//face6
		{2, 15, 13}, {2, 6, 15}, {2, 10, 6},
		//face7
		{13, 3, 17}, {13, 17, 16}, {13, 16, 2},
		//face8
		{3, 7, 11},	{3, 15, 7},	{3, 13, 15},
		//face9
		{4, 10, 8}, {4, 6, 10}, {4, 18, 6},
		//face10
		{14, 5, 19}, {14, 19, 18}, {14, 18, 4},
		//face11
		{5, 7, 19}, {5, 11, 7}, {5, 9, 11},
		//face12
		{15, 19, 7}, {15, 18, 19}, {15, 6, 18 },
	};

	std::vector<Vertex> vertices{
		Vertex({ 1, 1, 1 }),
		Vertex({1, 1, -1}),
		Vertex({1, -1, 1}),
		Vertex({1, -1, -1}),
		Vertex({-1, 1, 1}),
		Vertex({-1, 1, -1}),
		Vertex({-1, -1, 1}),
		Vertex({-1, -1, -1}),
		Vertex({0, 0.618, 1.618}),
		Vertex({0, 0.618, -1.618}),
		Vertex({0, -0.618, 1.618}),
		Vertex({0, -0.618, -1.618}),
		Vertex({0.618, 1.618, 0}),
		Vertex({0.618, -1.618, 0}),
		Vertex({-0.618, 1.618, 0}),
		Vertex({-0.618, -1.618, 0}),
		Vertex({1.618, 0, 0.618}),
		Vertex({1.618, 0, -0.618}),
		Vertex({-1.618, 0, 0.618}),
		Vertex({-1.618, 0, -0.618}),
	};

	std::shared_ptr<CTriangleMeshData> pMeshData = std::make_shared<CTriangleMeshData>(vertices, faces);

	m_mash = CTriangleMesh(pMeshData, transform);
}

bool CDodecahedron::Hit(CRay const& ray, CIntersection& intersection) const
{
	return m_mash.Hit(ray, intersection);
}
