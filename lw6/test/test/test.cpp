#define M_PI 3.1415926535897932384626433832795

// Check if the point p is on the left side of the line p0p1
bool PointIsOnTheLeft(vec2 p0, vec2 p1, vec2 p)
{
	vec2 p0p1 = p1 - p0;
	// find the orthogonal vector to p0p1
	vec2 n = vec2(-p0p1.y, p0p1.x);

	// Find the dot product between n and (p - p0)
	return dot(p - p0, n) > 0.0;
}


bool PointIsInsideTriangle(vec2 p0, vec2 p1, vec2 p2, vec2 p)
{
	return
		PointIsOnTheLeft(p0, p1, p) &&
		PointIsOnTheLeft(p1, p2, p) &&
		PointIsOnTheLeft(p2, p0, p);
}

bool PointIsInsideStar(vec2 center, int r, vec2 p)
{
	vec2 points[5];
	float angle = 0;
	const float step = 2 * M_PI / 5;

	for (int i = 0; i < 5; i++)
	{
		points[i] = vec2(r * cos(angle), r * sin(angle));
		angle += step;
	}

	bool isInStar = false;

	angle = M_PI / 3;

	vec2 p0 = points[0];
	vec2 p1 = vec2(sin(angle) * r / 2, cos(angle) * r / 2);
	vec2 p2 = center;

	return PointIsInsideTriangle(p0, p1, p2, p);
}
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
