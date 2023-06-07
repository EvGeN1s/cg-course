#define M_PI 3.1415926535897932384626433832795

// vertex end phase position


// current animation phase
uniform float phase;
uniform float radius;
uniform float smallRadius;

vec3 GetTorPoint(float posX, float posY, float R, float smallR)
{
	vec3 resPoint;

	resPoint.x = (R + smallR * cos(posX)) * cos(posY);
	resPoint.y = (R + smallR * cos(posX)) * sin(posY);
	resPoint.z = smallR * sin(posX);

	return resPoint;
}

vec3 GetSpherePoint(float posX, float posY, float R)
{
	vec3 resPoint;
	posX = posX / 2 - M_PI / 2;

	resPoint.x = R * cos(posX) * cos(posY);
	resPoint.y = R * cos(posX) * sin(posY);
	resPoint.z = R * sin(posX);

	return resPoint;
}

void main()
{
	// Calculate vertex position by interpolating 
	// startPosition (gl_Vertex) and endPosition
	//vec4 vertex = mix(gl_Vertex, vec4(endPosition, 1.0), phase);
	vec4 spherePoint = vec4(GetSpherePoint(gl_Vertex.x, gl_Vertex.y, radius + smallRadius), 1.0);
	vec4 torPoint = vec4(GetTorPoint(gl_Vertex.x, gl_Vertex.y, radius, smallRadius), 1.0);

	vec4 vertex = mix(spherePoint, torPoint, phase);
	// Transform calculated position
	gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * vertex;

	// Specify front color
	gl_FrontColor = gl_Color;
}
