// classic Phong fragment shader
#version 410

in vec4 vPosition;
in vec3 vNormal;
in vec3 fragPos;

uniform vec3 Ka; // ambient material colour
uniform vec3 Kd; // diffuse material colour
uniform vec3 Ks; // specular material colour
uniform float specularPower; // material specular power


//uniform vec3 Ia; // ambient light colour
//uniform vec3 Id; // diffuse light colour
//uniform vec3 Is; // specular light colour

//uniform vec3 lightPosition;
//uniform float constant;
//uniform float linear;
//uniform float quadratic;

// Lights to use
struct DirLight
{
    vec3 direction;
    vec3 Ia, Id, Is;
};

struct PointLight
{
    vec3 position;
    
    float constant, linear, quadratic;

    vec3 Ia, Id, Is;
};

struct SpotLight
{
    vec3 position, direction;
    float cutOff, outerCutOff;
    float constant, linear, quadratic;
    vec3 Ia, Id, Is;
};
// To be assigned in CPP file
uniform DirLight dirLight;
uniform PointLight pointLight;
uniform SpotLight spotLight;

//  Functions For Calucating Correct Light
vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir);
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

uniform vec3 cameraPosition; // camera position

out vec4 FragColour;

void main() 
{
    // ensure normal and light direction are normalised
    vec3 norm = normalize(vNormal);
    //vec3 viewDir = normalize(cameraPosition - fragPos);
    vec3 viewDir = normalize(cameraPosition - vPosition.xyz);

    vec3 result = CalcDirLight(dirLight, norm, viewDir);
    result += CalcPointLight(pointLight, norm, fragPos, viewDir);
    result += CalcSpotLight(spotLight, norm, fragPos, viewDir);

    // output final colour
    FragColour = vec4(result, 1 );
}

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);

    // calculate lambert term (negate light direction) //-L
    float lambertTerm = max( 0, min( 1, dot( normal, lightDir ) ) );

    // calculate view vector and reflection vector
    vec3 V = normalize(cameraPosition - vPosition.xyz);
    vec3 R = reflect( lightDir, normal );
    
    // calculate specular term
    float specularTerm = pow( max( 0, dot( R, viewDir ) ), specularPower );

    //  calculate each colour properties    
    vec3 ambient = light.Ia * Ka;
    vec3 diffuse = light.Id * Kd* lambertTerm; 
    vec3 specular = light.Is * Ks * specularTerm;

    return (ambient + diffuse + specular);
}
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    // normalize light vector
    vec3 lightDir = normalize(light.position - fragPos);

    // calculate lambert term (negate light direction) //-L
    float lambertTerm = max( 0, min( 1, dot( normal, lightDir ) ) );

    // calculate view vector and reflection vector
    vec3 V = normalize(cameraPosition - vPosition.xyz);
    vec3 R = reflect( -lightDir, normal );
    
    // calculate specular term
    float specularTerm = pow( max( 0, dot( R, viewDir ) ), specularPower );

    // attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

    //  calculate each colour properties    
    vec3 ambient = light.Ia * Ka;
    vec3 diffuse = light.Id * Kd* lambertTerm; 
    vec3 specular = light.Is * Ks * specularTerm;

    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;

    return (ambient + diffuse + specular);
}
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);

    // calculate lambert term (negate light direction) //-L
    float lambertTerm = max( 0, min( 1, dot( normal, lightDir ) ) );

    // calculate view vector and reflection vector
    vec3 V = normalize(cameraPosition - vPosition.xyz);
    vec3 R = reflect( -lightDir, normal );
    
    // calculate specular term
    float specularTerm = pow( max( 0, dot( R, viewDir ) ), specularPower );

    // attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

    // spotlight intensity
    float theta = dot(lightDir, normalize(-light.direction)); 
    float epsilon = light.cutOff - light.outerCutOff;
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);

    //  calculate each colour properties    
    vec3 ambient = light.Ia * Ka;
    vec3 diffuse = light.Id * Kd* lambertTerm; 
    vec3 specular = light.Is * Ks * specularTerm;

    ambient *= attenuation * intensity;
    diffuse *= attenuation * intensity;
    specular *= attenuation * intensity;

    return (ambient + diffuse + specular);
}