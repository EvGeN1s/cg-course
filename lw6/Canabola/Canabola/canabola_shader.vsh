#define M_PI 3.1415926535897932384626433832795


float getCanabolaRadius(float x)
{
	return (1 + sin(x)) * (1 + 0.9 * cos(8 * x)) * (1 + 0.1 * cos(24 * x)) * (0, 5 + 0.3 * cos(140 * x));
}

float starRadius(float x)
{
	const int n = 8;
	const int m = 6;
	const float k = 0.7;
	const float limit = 0.01;


	float topSin = asin(k);
	if (topSin == 0)
	{
		topSin = limit;
	}
	float botSin = asin(k * cos(n * x));
	if (botSin == 0)
	{
		botSin = limit;
	}

	float top = cos((2 * topSin + M_PI * m) / (2 * n));
	float bot = cos((2 * botSin + M_PI * m) / (2 * n));


	if (bot == 0)
	{
		bot = limit;
	}

	float r = top / bot;

	return abs(r);
}

void main()
{
	vec4 position = gl_Vertex;
	float r = starRadius(position.x);
	//float r = 2 * sin(4 * position.x);

	position.y = r * sin(position.x);
	position.x = r * cos(position.x);

	//gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * position;
	gl_Position = position;
}