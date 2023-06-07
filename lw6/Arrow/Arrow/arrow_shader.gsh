#version 120
#extension GL_EXT_geometry_shader4 : enable
#define M_PI 3.1415926535897932384626433832795
varying in vec2 VTexCoord0[2];


void main()
{
	// Rectangle center is a position of the original primitive
	vec4 start = gl_PositionIn[0];
	vec4 end = gl_PositionIn[1];
	//vec4 end = vec4(0.0, 0.0, 0.0, 1.0);
	//vec2 line = vec2(end.x - start.x, end.y - start.x);

	float r = length(vec2(end.x - start.x, end.y - start.x)) / 4;
	float angle = acos((end.x - start.x) / r);

	vec2 s1 = vec2(r * cos(angle - M_PI / 6), r * sin(angle - M_PI / 6));

	vec2 s2 = vec2(r * cos(M_PI / 2 - angle - M_PI / 6), r * sin(M_PI / 2 - angle - M_PI / 6));

	 // Bottom left	
	gl_Position = start;
	gl_TexCoord[0].xy = vec2(start.x, start.y);
	EmitVertex();

	// Bottom right
	gl_Position = end;
	gl_TexCoord[0].xy = vec2(end.x, end.y);
	EmitVertex();

	// Top left
	/*gl_Position = vec4(s1, 1.0, 1.0);
	gl_TexCoord[0].xy = vec2(s1.x, s1.y);
	EmitVertex();*/

	// Top right
	/*gl_Position = vec4(s2, 1.0, 1.0);
	gl_TexCoord[0].xy = vec2(s2.x, s2.y);
	EmitVertex();*/

	// Emit a triangle strip
	EndPrimitive();
}
