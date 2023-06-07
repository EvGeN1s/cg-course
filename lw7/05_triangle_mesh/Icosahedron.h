#pragma once
#include "GeometryObjectImpl.h"
#include "TriangleMesh.h"

class CIcosahedron : public CGeometryObjectImpl
{
public:
	CIcosahedron(CMatrix4d const& transform = CMatrix4d());

	virtual bool Hit(CRay const& ray, CIntersection& intersection)const;
private:
	CTriangleMesh m_mash;
};

