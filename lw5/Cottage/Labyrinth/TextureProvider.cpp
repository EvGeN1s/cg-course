#include "TextureProvider.h"
#include "pch.h"
#include <iostream>

#ifndef GL_CLAMP_TO_EDGE_EXT
#define GL_CLAMP_TO_EDGE_EXT 0x812F
#endif
CTextureProvider::CTextureProvider()
{
	m_textureLoader.SetWrapMode(GL_CLAMP_TO_EDGE_EXT, GL_CLAMP_TO_EDGE_EXT);
}

CTexture2D* CTextureProvider::GetTexture(TextureName textureName) const
{
	if (textureName == TextureName::WOOD_TEXTURE)
	{
		LoadTexture(textureName, m_woodTexture);
		return &(m_woodTexture);
	}
	else if (textureName == TextureName::STONES_TEXTURE)
	{
		LoadTexture(TextureName::STONES_TEXTURE, m_stoneTexture);
		return &(m_stoneTexture);
	}
	else if (textureName == TextureName::LAND_TEXTURE)
	{
		LoadTexture(textureName, m_landTexture);
		return &(m_landTexture);
	}
	else if (textureName == TextureName::DOOR_TEXTURE)
	{
		LoadTexture(textureName, m_doorTexture);
		return &(m_doorTexture);
	}
	else if (textureName == TextureName::STEEL_TEXTURE)
	{
		LoadTexture(textureName, m_steelTexture);
		return &(m_steelTexture);
	}
	else if (textureName == TextureName::GRASS_TEXTURE)
	{
		LoadTexture(textureName, m_grassTexture);
		return &(m_grassTexture);
	}
	else if (textureName == TextureName::WINDOW_TEXTURE)
	{
		LoadTexture(textureName, m_windowTexture);
		return &(m_windowTexture);
	}
	else if (textureName == TextureName::SKY_TEXTURE)
	{
		LoadTexture(textureName, m_skyTexture);
		return &(m_skyTexture);
	}
	throw std::exception("There are no texture for this name");
}


void CTextureProvider::LoadTexture(TextureName name, CTexture2D& texture) const
{
	if (!texture)
	{
		std::wstring fileName = GetTextureFileName(name);
		texture.Attach(m_textureLoader.LoadTexture2D(fileName));		
	}
}

std::wstring CTextureProvider::GetTextureFileName(TextureName name) const
{
	if (name == TextureName::WOOD_TEXTURE)
	{
		return L"./texture/wood_texture.png";
	}
	else if (name == TextureName::STONES_TEXTURE)
	{
		return L"./texture/stones_texture.png";
	}
	else if (name == TextureName::LAND_TEXTURE)
	{
		return L"./texture/land_texture.jpg";
	}
	else if (name == TextureName::DOOR_TEXTURE)
	{
		return L"./texture/door_texture.png";
	}
	else if (name == TextureName::STEEL_TEXTURE)
	{
		return L"./texture/steel_texture.png";
	}
	else if (name == TextureName::GRASS_TEXTURE)
	{
		return L"./texture/grass_texture.jpg";
	}
	else if (name == TextureName::WINDOW_TEXTURE)
	{
		return L"./texture/window_texture.png";
	}
	else if (name == TextureName::SKY_TEXTURE)
	{
		return L"./texture/sky_texture2.jpg";
	}
	else
	{
		return std::wstring();
	}
}
