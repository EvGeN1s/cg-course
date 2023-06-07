#pragma once
#include "GeometryObjectImpl.h"
#include "TriangleMesh.h"

class CDodecahedron: public CGeometryObjectImpl
{
public: 
	CDodecahedron(CMatrix4d const& transform = CMatrix4d());

	virtual bool Hit(CRay const& ray, CIntersection& intersection)const;
private:

	CTriangleMesh m_mash;
};

