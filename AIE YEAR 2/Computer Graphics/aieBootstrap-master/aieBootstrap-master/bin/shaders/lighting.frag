// classic Phong fragment shader
#version 410

in vec4 vPosition;
in vec3 vNormal;
in vec3 fragPos;

uniform vec3 Ka; // ambient material colour
uniform vec3 Kd; // diffuse material colour
uniform vec3 Ks; // specular material colour
uniform float specularPower; // material specular power


uniform vec3 Ia; // ambient light colour
uniform vec3 Id; // diffuse light colour
uniform vec3 Is; // specular light colour

uniform vec3 lightPosition;
uniform float constant;
uniform float linear;
uniform float quadratic;


uniform vec3 cameraPosition; // camera position

out vec4 FragColour;

void main() 
{
    // ensure normal and light direction are normalised
    vec3 N = normalize(vNormal);

    // normalize light vector
    vec3 L = normalize(lightPosition - fragPos);

    // calculate lambert term (negate light direction) //-L
    float lambertTerm = max( 0, min( 1, dot( N, L ) ) );

    // calculate view vector and reflection vector
    vec3 V = normalize(cameraPosition - vPosition.xyz);
    vec3 R = reflect( L, N );
    
    // calculate specular term
    float specularTerm = pow( max( 0, dot( R, V ) ), specularPower );

    //  calculate each colour properties    
    vec3 ambient = Ia * Ka;
    vec3 diffuse = Id * Kd* lambertTerm; 
    vec3 specular = Is * Ks * specularTerm;

    // attenuation
    float distance = length(lightPosition - fragPos);
    float attenuation = 1.0 / (constant + linear * distance + quadratic * (distance * distance));    

    ambient  *= attenuation;  
    diffuse   *= attenuation;
    specular *= attenuation; 

    // output final colour
    FragColour = vec4(ambient + diffuse + specular, 1 );

    // output lambert as grayscale
    //FragColour = vec4( lambertTerm, lambertTerm, lambertTerm, 1 ); this doesn't use Ia,Is or Id
}