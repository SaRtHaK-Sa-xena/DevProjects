// a normal map vertex shader
#version 410
layout( location = 0 ) in vec4 Position;
layout( location = 1 ) in vec4 Normal;
layout( location = 2 ) in vec2 TexCoord;
layout( location = 3 ) in vec4 Tangent;

out vec2 vTexCoord;
out vec3 vNormal;
out vec3 vTangent;  // Normal Matrix * Tangent.xyz
out vec3 vBiTangent; // crossProduct between vTangent&vNormal * Tangent.w
out vec4 vPosition;
out vec3 fragPos;

uniform mat4 ProjectionViewModel;

// we need the model matrix seperate
uniform mat4 ModelMatrix;

// we need this matrix to transform the normal
uniform mat3 NormalMatrix;

void main() 
{
    vTexCoord = TexCoord;
    vPosition = ModelMatrix * Position;
    vNormal = NormalMatrix * Normal.xyz;
    vTangent = NormalMatrix * Tangent.xyz;
    vBiTangent = cross(vNormal, vTangent) * Tangent.w;

    fragPos = vec3(vPosition);
    //fragPos = vec3(ModelMatrix * vec4(Position));

    gl_Position = ProjectionViewModel * Position;
}