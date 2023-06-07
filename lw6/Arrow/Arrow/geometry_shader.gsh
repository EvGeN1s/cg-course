#version 120
#extension GL_EXT_geometry_shader4 : enable
#define M_PI 3.1415926535897932384626433832795

// Rectangle size
uniform float Size;

void main()
{
	// Rectangle center is a position of the original primitive
	vec4 center = gl_PositionIn[0];


	for (float angle = 0; angle < 2 * M_PI + M_PI / 16; angle += M_PI / 16)
	{
		float rx = Size * cos(angle);
		float ry = Size * sin(angle);

		gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * (center + vec4(rx, ry, 0.0, 0.0));
		gl_TexCoord[0].xy = vec2(1, 1);
		EmitVertex();
	}
	
	EndPrimitive();
}
