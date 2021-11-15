#shader vertex
#version 330 core

layout(location = 0) in vec4 position;

uniform mat4 u_MVP;

void main() {
	gl_position = u_MVP * position;

};

#shader fragment
#version 330 core

out vec4 fragColor;

uniform vec4 lightColor;
uniform vec4 objectColor;

void main() {
	fragColor = lightColor * objectColor;
};
