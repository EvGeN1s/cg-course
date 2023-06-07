#pragma once
class KleinBottle
{
public:
	KleinBottle(double radius);

	void Draw() const;

	~KleinBottle() = default;

private:
	double m_radius;
	double m_scale;

	void DrawTopSide()const;
	void DrawTopSidePart(double u, double v)const;

	void DrawBottomSide()const;
	void DrawBottomSidePart(double u, double v)const;
};

