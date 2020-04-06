// a normal map fragment shader
#version 410
in vec2 vTexCoord;
in vec3 vNormal;
in vec4 vPosition;
in vec3 vTangent;
in vec3 vBiTangent;
in vec3 fragPos;

out vec4 FragColour;

uniform sampler2D diffuseTexture;
uniform sampler2D specularTexture;
uniform sampler2D normalTexture;

uniform vec3 Ka; // material ambient
uniform vec3 Kd; // material diffuse
uniform vec3 Ks; // material specular
uniform float specularPower;

uniform vec3 Ia; // light ambient
uniform vec3 Id; // light diffuse
uniform vec3 Is; // light specular
uniform vec3 lightPosition;
uniform vec3 lightDirection;
uniform float constant;
uniform float linear;
uniform float quadratic;

uniform vec3 cameraPosition;

void main() 
{
    vec3 N = normalize(vNormal);
    vec3 L = normalize(lightPosition - fragPos);
    vec3 T = normalize(vTangent);
    vec3 B = normalize(vBiTangent);
    
    //  Tangent Basis Matrix->
    // xAxis = Tangent
    // yAxis = BiTangent
    // zAxis = Normal
    mat3 TBN = mat3(T,B,N);


    vec3 texDiffuse = texture( diffuseTexture, vTexCoord ).rgb;
    vec3 texSpecular = texture( specularTexture, vTexCoord ).rgb;
    vec3 texNormal = texture( normalTexture, vTexCoord ).rgb;

    //N = TBN * (texNormal * 2-1);

    // calculate lambert term //-L
    float lambertTerm = max( 0, dot( N, L ) );

    // calculate view vector and reflection vector
    vec3 V = normalize(cameraPosition - vPosition.xyz);
    vec3 R = reflect( L, N );

    // calculate specular term
    float specularTerm = pow( max( 0, dot( R, V ) ), specularPower );

    // calculate each light property
    vec3 ambient = Ia * Ka;
    vec3 diffuse = Id * Kd * texDiffuse * lambertTerm;
    vec3 specular = Is * Ks * texSpecular * specularTerm;

    // attenuation
    float distance = length(lightPosition - fragPos);
    float attenuation = 1.0 / (constant + linear * distance + quadratic * (distance * distance));    

    ambient  *= attenuation;  
    diffuse   *= attenuation;
    specular *= attenuation;

    FragColour = vec4(ambient + diffuse + specular, 1);
}