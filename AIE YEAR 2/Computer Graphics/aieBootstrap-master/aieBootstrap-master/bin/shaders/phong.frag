// classic Phong fragment shader
#version 410

in vec3 vNormal;

uniform vec3 Ia; // ambient light colour
uniform vec3 Id; // diffuse light colour
uniform vec3 Is; // specular light colour
uniform vec3 lightDirection;

out vec4 FragColour;

void main() 
{
    // ensure normal and light direction are normalised
    vec3 N = normalize(vNormal);
    vec3 L = normalize(lightDirection);

    // calculate lambert term (negate light direction)
    float lambertTerm = max( 0, min( 1, dot( N, -L ) ) );

    // calculate diffuse
    vec3 diffuse = Id * lambertTerm;

    // output final colour
    FragColour = vec4( diffuse, 1 );

    // output lambert as grayscale
    FragColour = vec4( lambertTerm, lambertTerm, lambertTerm, 1 );
}