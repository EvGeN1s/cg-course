#pragma once
#include "TextureProvider.h"
#include "FigureProvider.h"
#include "Cube.h"

class Land
{
public:
	void Draw() const;
private:
	FigureProvider m_figureProvider;
	CTextureProvider m_textureProvider;
};

