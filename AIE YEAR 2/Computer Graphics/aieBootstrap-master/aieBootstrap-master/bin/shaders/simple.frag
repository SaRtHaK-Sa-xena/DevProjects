// a simple flat colour shader
#version 410

// use material diffuse
uniform vec3 kD;

out vec4 FragColour;

void main() {
FragColour = vec4(kD, 1);
}