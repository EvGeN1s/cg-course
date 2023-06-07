#pragma once
#include <functional>
#include <memory>
#include "CPyramid.h"
#include "Cube.h"
#include "TextureProvider.h"
#include "FigureProvider.h"

class CHouse
{
public:
	CHouse() {};
	void Draw() const;

private:
	void DrawHouseMainPart() const;
	void DrawBalcony() const;
	void DrawRoof() const;
	void DrawGarage() const;
	void DrawDoor() const;
	void DrawWindows() const;

	void DrawFirstFloorFront(std::shared_ptr<Cube> cube) const;
	void DrawFirstFloorBack(std::shared_ptr<Cube> cube) const;
	void DrawSecondFloorFront(std::shared_ptr<Cube> cube) const;
	void DrawSecondFloorBack(std::shared_ptr<Cube> cube) const;

	FigureProvider m_figureProvider;
	CTextureProvider m_textureProvider;
};