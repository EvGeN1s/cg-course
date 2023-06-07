#include "FigureProvider.h"
#include "Cube.h"
#include "CPyramid.h"

std::shared_ptr<Cube> FigureProvider::CreateCube(float size) const
{
	auto cube = std::make_shared<Cube>(size);
	cube->SetSpecularColor({ 1, 1, 1, 1 });
	cube->SetShininess(4.0f);

	return cube;
}

std::shared_ptr<CPyramid> FigureProvider::CreatePyramid(CPyramid::PyramidSideSize&& size, float height) const
{
	auto pyramid = std::make_shared<CPyramid>(std::move(size), height);
	pyramid->SetSpecularColor({ 1, 1, 1, 1 });
	pyramid->SetShininess(4.0f);

	return pyramid;
}