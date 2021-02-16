#version 400 core
layout(vertices = 4) out;

in Vertex {
	vec3 worldPos;
	vec2 texCoord;
	vec3 normal;
} IN[];

out Vertex {
	vec3 worldPos;
	vec2 texCoord;
	vec3 normal;
} OUT[];

void main() {
	gl_TessLevelInner[0] = 32;
	gl_TessLevelInner[1] = 32;
	gl_TessLevelOuter[0] = 32;
	gl_TessLevelOuter[1] = 32;
	gl_TessLevelOuter[2] = 32;
	gl_TessLevelOuter[3] = 32;

	OUT[gl_InvocationID].texCoord = IN[gl_InvocationID].texCoord;

	gl_out[gl_InvocationID].gl_Position = gl_in[gl_InvocationID].gl_Position;
}