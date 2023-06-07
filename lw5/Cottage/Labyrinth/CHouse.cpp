#include "CHouse.h"

void CHouse::Draw() const
{
	DrawHouseMainPart(); 
	DrawRoof();
	DrawDoor();
	DrawGarage();
	DrawBalcony();	
	DrawWindows();
}

void CHouse::DrawHouseMainPart() const
{
	auto cube = m_figureProvider.CreateCube(2);

	auto woodTexture = m_textureProvider.GetTexture(TextureName::WOOD_TEXTURE);
	glEnable(GL_TEXTURE_2D);

	woodTexture->Bind();

	DrawFirstFloorFront(cube);
	DrawFirstFloorBack(cube);
	DrawSecondFloorFront(cube);
	DrawSecondFloorBack(cube);
}

void CHouse::DrawBalcony() const
{
	auto cube = m_figureProvider.CreateCube(0.8);
	auto stoneTexture = m_textureProvider.GetTexture(TextureName::STONES_TEXTURE);
	glEnable(GL_TEXTURE_2D);
	stoneTexture->Bind();

	glPushMatrix();
	{
		glTranslatef(-3.9f, 0.4f, 1.9f);
		glScalef(0.2f, 1.0f, 0.2f);
		cube->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(-3.9f, 0.4f, 0.9f);
		glScalef(0.2f, 1.0f, 0.2f);
		cube->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(-2.9f, 0.4f, 1.9f);
		glScalef(0.2f, 1.0f, 0.2f);
		cube->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(-2.9f, 0.8f, 1.9f);
		glScalef(2.7f, 0.2f, 0.2f);
		cube->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(-3.9f, 0.8f, 0.9f);
		glScalef(0.2f, 0.2f, 2.7f);
		cube->Draw();
	}
	glPopMatrix();
}

void CHouse::DrawRoof() const
{
	auto pyramid = m_figureProvider.CreatePyramid({ 1.0f, 2.0f, 3.0f, 4.0f }, 1);
	auto woodTexture = m_textureProvider.GetTexture(TextureName::STONES_TEXTURE);

	glEnable(GL_TEXTURE_2D);

	woodTexture->Bind();

	glPushMatrix();
	{
		glTranslatef(0.0f, 1.0f, 0.0f);
		glScalef(4.0f, 2.0f, 4.0f);
		pyramid->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(-3.0f, 1.5f, -1.0f);
		glScalef(2.0f, 1.0f, 2.0f);
		pyramid->Draw();
	}
	glPopMatrix();
}

void CHouse::DrawGarage() const
{
	auto cube = m_figureProvider.CreateCube(1.8);

	auto steelTexture = m_textureProvider.GetTexture(TextureName::STEEL_TEXTURE);


	glEnable(GL_TEXTURE_2D);
	steelTexture->Bind();

	glPushMatrix();
	{
		glTranslatef(0.0f, -1.0f, 2.0f);
		glScalef(1.2f, 1.0f, 0.05f);
		cube->Draw();
	}
	glPopMatrix();
}

void CHouse::DrawDoor() const
{
	auto cube = m_figureProvider.CreateCube(1.0);
	auto doorTexture = m_textureProvider.GetTexture(TextureName::DOOR_TEXTURE);
	glEnable(GL_TEXTURE_2D);
	doorTexture->Bind();

	glPushMatrix();
	{
		glTranslatef(-3.0f, -1.2f, 2.0f);
		glScalef(0.9f, 1.2f, 0.05f);
		cube->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(-3.0f, 0.8f, 0.0f);
		glScalef(0.9f, 1.2f, 0.05f);
		cube->Draw();
	}
	glPopMatrix();

}

void CHouse::DrawWindows() const
{
	auto cube = m_figureProvider.CreateCube(1);
	auto glassTexture = m_textureProvider.GetTexture(TextureName::WINDOW_TEXTURE);
	glEnable(GL_TEXTURE_2D);
	glassTexture->Bind();

	glPushMatrix();
	{
		glTranslatef(0.0f, 1.0f, 2.0f);
		glScalef(2.0f, 1.0f, 0.1f);
		cube->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(-2.0f, 1.0f, 1.0f);
		glScalef(0.1f, 1.0f, 1.0f);
		cube->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(2.0f, 0.0f, 0.0f);
		glScalef(0.1f, 2.5f, 1.2f);
		cube->Draw();
	}
	glPopMatrix();
}

void CHouse::DrawFirstFloorFront(std::shared_ptr<Cube> cube) const
{
	glPushMatrix();
	{
		glTranslatef(-3.0f, -1.0f, 1.0f);
		cube->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{

		glTranslatef(-1.0f, -1.0f, 1.0f);
		cube->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{

		glTranslatef(1.0f, -1.0f, 1.0f);
		cube->Draw();
	}
	glPopMatrix();
}

void CHouse::DrawFirstFloorBack(std::shared_ptr<Cube> cube) const
{
	glPushMatrix();
	{
		glTranslatef(-3.0f, -1.0f, -1.0f);
		cube->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{

		glTranslatef(-1.0f, -1.0f, -1.0f);
		cube->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{

		glTranslatef(1.0f, -1.0f, -1.0f);
		cube->Draw();
	}
	glPopMatrix();
}

void CHouse::DrawSecondFloorFront(std::shared_ptr<Cube> cube) const
{
	glPushMatrix();
	{
		glTranslatef(-1.0f, 1.0f, 1.0f);
		cube->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{

		glTranslatef(1.0f, 1.0f, 1.0f);
		cube->Draw();
	}
	glPopMatrix();
}

void CHouse::DrawSecondFloorBack(std::shared_ptr<Cube> cube) const
{
	glPushMatrix();
	{
		glTranslatef(-3.0f, 1.0f, -1.0f);
		cube->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{

		glTranslatef(-1.0f, 1.0f, -1.0f);
		cube->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{

		glTranslatef(1.0f, 1.0f, -1.0f);
		cube->Draw();
	}
	glPopMatrix();
}
