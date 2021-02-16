#version 400 core

uniform sampler2D mainTex;
uniform sampler2D secondTex;
uniform float time;

uniform vec3	cameraPos;

uniform vec3	lightColour;
uniform vec3	lightPos;
uniform float	lightRadius;

in Vertex {
	vec3 worldPos;
	vec2 texCoord;
	vec3 normal;
} IN;

out vec4 fragColor;

void main(void) {

	float rate = ((sin(0.75*time) + 1)/2);

	vec3 incident	= normalize(lightPos - IN.worldPos);
	vec3 viewDir	= normalize(cameraPos - IN.worldPos);
	vec3 halfDir	= normalize(incident + viewDir);

	float dist 		= length(lightPos - IN.worldPos);
	float atten		= 1.0 - clamp(dist / lightRadius, 0.0, 1.0);
	float lambert	= max(0.0, dot(incident, IN.normal));

	float rFactor	= max(0.0, dot(halfDir, normalize(IN.normal)));
	float sFactor	= pow(rFactor, 50.0);

	vec4 t0 	= texture(mainTex, IN.texCoord);
	vec3 ambient 	= t0.rgb * lightColour * 0.1;
	vec3 diffuse 	= t0.rgb * lightColour * lambert * atten;
	

	vec4 t1 	= texture(secondTex, IN.texCoord);
	vec3 ambient2 	= t1.rgb * lightColour * 0.1;
	vec3 diffuse2 	= t1.rgb * lightColour * lambert * atten;
	

	vec3 specular 	= lightColour * sFactor * atten;
	
	fragColor 		= t0*(1-rate) + t1*rate;
	
	}
