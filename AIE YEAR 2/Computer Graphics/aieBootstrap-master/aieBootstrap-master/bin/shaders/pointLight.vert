// classic PointLight vertex shader
#version 410
layout( location = 0 ) in vec4 Position;
layout( location = 1 ) in vec4 Normal;

out vec4 vPosition;
out vec3 vNormal;
out vec3 fragPos;

uniform mat4 ProjectionViewModel;

// need this matrix to transform the position
uniform mat4 ModelMatrix;

//  need this matrix to transform the normal
uniform mat3 NormalMatrix;

void main() 
{
    vPosition = ModelMatrix * Position;
    vNormal = NormalMatrix * Normal.xyz;

    fragPos = vec3(ModelMatrix * vec4(Position));
    gl_Position = ProjectionViewModel * Position;
}