#pragma once
#include "Cube.h"
#include "CPyramid.h"

class FigureProvider
{
public:
	std::shared_ptr<Cube> CreateCube(float size) const;
	std::shared_ptr<CPyramid> CreatePyramid(CPyramid::PyramidSideSize&& size, float height) const;
};
