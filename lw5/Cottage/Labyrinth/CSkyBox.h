#pragma once
#include <string>
#include "Cube.h"
#include "TextureProvider.h"

class CSkyBox
{
public:
	CSkyBox(
		std::wstring const& texture 
	);
	void Draw()const;
private:
	mutable bool m_initialized;
	mutable Cube m_cube;
	std::wstring m_texture;
	CTextureProvider m_textureProvider;
};


