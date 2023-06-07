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

bool PointIsInsideStar(vec2 center, float r, float startAngle, vec2 p)
{
	vec2 points[5];
	float angle = startAngle + M_PI / 2;
	float step = 2 * M_PI / 5;

	for (int i = 0; i < 5; i++)
	{
		points[i] = vec2(center.x + r * cos(angle), center.y +  r * sin(angle));
		angle += step;
	}

	bool isInStar = false;

	angle = startAngle + M_PI / 6;
	step = M_PI * 1 / 3;

	float scale = r *  1 / 3; //sin(M_PI / 5);

	for (int i = 0; i < 4; i++)
	{
		vec2 p0 = points[i];
		vec2 p1 = center;
		vec2 p2 = vec2(center.x + cos(angle) * scale, center.y + sin(angle) * scale);	
		vec2 p4 = vec2(center.x + cos(angle + M_PI * 3 / 4) * scale, center.y + sin(angle + M_PI * 3 / 4) * scale);

		isInStar = isInStar || PointIsInsideTriangle(p0, p1, p2, p)	|| PointIsInsideTriangle(p0, p4, p1, p);
		if (isInStar) 
		{
			return true;
		}
		angle += step;
	}

	angle = startAngle - M_PI /6;
	vec2 p0 = points[4];
	vec2 p1 = center;
	vec2 p2 = vec2(center.x + cos(angle) * scale, center.y + sin(angle) * scale);	
	vec2 p4 = vec2(center.x + cos(angle + M_PI * 3 / 4) * scale, center.y + sin(angle + M_PI * 3 / 4) * scale);

	isInStar = PointIsInsideTriangle(p0, p1, p2, p)	|| PointIsInsideTriangle(p0, p4, p1, p);
	 
	return isInStar;
}

bool PointInsideStars(vec2 pos)
{
	bool inside = false;

	const vec2 p0 = vec2(0.8, 2.7);
	inside = PointIsInsideStar(p0, 0.6, 0, pos);

	const vec2 p1 = vec2(1.5, 3.5);
	inside = inside || PointIsInsideStar(p1, 0.2, - M_PI / 4, pos);

	const vec2 p2 = vec2(1.8, 3.1);
	inside = inside || PointIsInsideStar(p2, 0.2, M_PI / 6, pos);

	const vec2 p3 = vec2(1.8, 2.6);
	inside = inside || PointIsInsideStar(p3, 0.2, 0, pos);

	const vec2 p4 = vec2(1.5, 2.1);
	inside = inside || PointIsInsideStar(p4, 0.2, - M_PI / 4, pos);

	return inside;
}

void main()
{
    vec2 pos = gl_TexCoord[0].xy;
	
	if (PointInsideStars(pos))
	{
		gl_FragColor = vec4(0.98, 0.84, 0.01, 1.0);
	}
	else
	{
		// determine whether fraction part of x and y 
		// texture coordinate is greater than 0.5
		vec2 stepXY = step(vec2(0.5, 0.5), fract(pos));

		// determine whether the texture coordinate 
		// is within a black or white check
		gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
	}
}

