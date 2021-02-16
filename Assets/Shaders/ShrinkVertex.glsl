#version 400 core

uniform mat4 modelMatrix = mat4(1.0f);
uniform mat4 viewMatrix = mat4(1.0f);
uniform mat4 projMatrix = mat4(1.0f);
uniform float time;

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 colour;
layout(location = 2) in vec2 texCoord;
layout(location = 3) in vec3 normal;


out Vertex {
	vec3 worldPos;
	vec2 texCoord;
	vec3 normal;
} OUT;

void main(void) {
	
	float size = ((sin(0.75*time) + 1)/2);

	if(size > 0) {
		gl_Position = projMatrix * viewMatrix * modelMatrix* vec4(position.xyz*size, 1.0);

		OUT.texCoord = texCoord;

		mat3 normalMatrix = transpose(inverse(mat3(modelMatrix)));

		OUT.normal = normalize(normalMatrix * normalize(normal));
	}
}