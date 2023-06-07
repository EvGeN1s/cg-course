#include "Cube.h"


void Cube::Draw() const
{

	/*
	   Y
	   |
	   |
	   |
	   +---X
	  /
	 /
	Z
	   3----2
	  /    /|
	 /    / |
	7----6  |
	|  0 |  1
	|    | /
	|    |/
	4----5
	*/
	// ћассив координат вершин
	static constexpr float vertices[8][3] = {
		{ -1, -1, -1 }, // 0
		{ +1, -1, -1 }, // 1
		{ +1, +1, -1 }, // 2
		{ -1, +1, -1 }, // 3
		{ -1, -1, +1 }, // 4
		{ +1, -1, +1 }, // 5
		{ +1, +1, +1 }, // 6
		{ -1, +1, +1 }, // 7
	};

	struct CubeFace
	{
		unsigned char vertex0;
		unsigned char vertex1;
		unsigned char vertex2;
		unsigned char vertex3;
		GLfloat tex0s, tex0t;
		GLfloat tex1s, tex1t;
		GLfloat tex2s, tex2t;
		GLfloat tex3s, tex3t;
	};


	// ћассив координат граней (в пор€дке, совпадающем с
	// пор€дком объ€влени€ их в массиве цветов)
	// индексы вершин граней перечисл€ютс€ в пор€дке их обхода
	// против часовой стрелки (если смотреть на грань снаружи)
	static const CubeFace faces[] = {
		{4, 7, 3, 0, 0, 1, 0, 0, 1, 0, 1, 1},	// грань x<0
		{5, 1, 2, 6, 1, 1, 0, 1, 0, 0, 1, 0},	// грань x>0
		{4, 0, 1, 5, 0, 1, 0, 0, 1, 0, 1, 1},	// грань y<0
		{7, 6, 2, 3, 0, 0, 1, 0, 1, 1, 0, 1},		// грань y>0
		{0, 3, 2, 1, 0, 1, 0, 0, 1, 0, 1, 1},	// грань z<0
		{4, 5, 6, 7, 0, 0, 1, 0, 1, 1, 0, 1},	// грань z>0

	};
	static size_t const faceCount = sizeof(faces) / sizeof(*faces);

	glEnable(GL_COLOR_MATERIAL);
	// ÷вет вершины будет управл€ть диффузным и фоновым цветом материала
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, glm::value_ptr(m_specularColor));
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, m_shininess);

	glBegin(GL_QUADS);
	{
		for (size_t faceIndex = 0; faceIndex < faceCount; ++faceIndex)
		{
			CubeFace const& face = faces[faceIndex];

			// получаем вершины очередной грани куба
			auto p0 = glm::make_vec3(vertices[face.vertex0]);
			auto p1 = glm::make_vec3(vertices[face.vertex1]);
			auto p2 = glm::make_vec3(vertices[face.vertex2]);
			auto p3 = glm::make_vec3(vertices[face.vertex3]);

			// ¬ычисл€ем координаты вершин куба с учетом его размера
			p0 *= m_size * 0.5f;
			p1 *= m_size * 0.5f;
			p2 *= m_size * 0.5f;
			p3 *= m_size * 0.5f;

			// ¬ычисл€ем нормаль к грани куба через
			// векторное произведение его смежных сторон
			auto v01 = p1 - p0;
			auto v02 = p2 - p0;
			auto normal = glm::normalize(glm::cross(v01, v02));

			glNormal3fv(glm::value_ptr(normal));

			glTexCoord2f(face.tex0s, face.tex0t);
			glVertex3fv(glm::value_ptr(p0));

			glTexCoord2f(face.tex1s, face.tex1t);
			glVertex3fv(glm::value_ptr(p1));

			glTexCoord2f(face.tex2s, face.tex2t);
			glVertex3fv(glm::value_ptr(p2));

			glTexCoord2f(face.tex3s, face.tex3t);
			glVertex3fv(glm::value_ptr(p3));
		}
	}
	glEnd();
}

void Cube::SetSpecularColor(glm::vec4 color)
{
	m_specularColor = color;
}

void Cube::SetShininess(float shininess)
{
	m_shininess = shininess;
}