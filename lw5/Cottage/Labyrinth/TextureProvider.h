#pragma once
#include "TextureLoader.h"
#include "Texture.h"

enum class TextureName
{
	WOOD_TEXTURE,
	STONES_TEXTURE,
	DOOR_TEXTURE,
	STEEL_TEXTURE,
	GRASS_TEXTURE,
	LAND_TEXTURE,
	WINDOW_TEXTURE,
	SKY_TEXTURE,
};

class CTextureProvider
{
public:
	CTextureProvider();

	CTexture2D* GetTexture(TextureName name) const;
private:
	void LoadTexture(TextureName name, CTexture2D& texture) const;
	std::wstring GetTextureFileName(TextureName name)const;

	CTextureLoader m_textureLoader;

	mutable CTexture2D m_woodTexture;
	mutable CTexture2D m_stoneTexture;
	mutable CTexture2D m_landTexture;
	mutable CTexture2D m_doorTexture;
	mutable CTexture2D m_steelTexture;
	mutable CTexture2D m_grassTexture;
	mutable CTexture2D m_windowTexture;
	mutable CTexture2D m_skyTexture;
};

