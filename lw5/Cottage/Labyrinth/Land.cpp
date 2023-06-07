#include "Land.h"

void Land::Draw() const
{
	auto floor = m_figureProvider.CreateCube(1);

	auto landTexture = m_textureProvider.GetTexture(TextureName::LAND_TEXTURE);
	auto grassTexture = m_textureProvider.GetTexture(TextureName::GRASS_TEXTURE);
	glEnable(GL_TEXTURE_2D);

	for (auto indexI = -2.0f; indexI <= 2.0f; indexI += 1.0f)
	{
		for (auto indexJ = -2.0f; indexJ <= 2.0f; indexJ += 1.0f)
		{
			if ((int)indexI + (int)indexJ % 2 == 0)
			{
				landTexture->Bind();
			}
			else
			{
				grassTexture->Bind();
			}
			glPushMatrix();
			{
				glScalef(4.0f, 0.1f, 4.0f);
				glTranslatef(indexI, -20.0f, indexJ);
				floor->Draw();
			}
			glPopMatrix();
		}
	}
}
