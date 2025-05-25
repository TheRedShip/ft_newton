in vec3 Normal;
in vec3 FragPos;

out vec4 FragColor;

uniform vec3 light_pos;
uniform vec3 object_color;
uniform vec3 view_pos;

void main()
{
    vec3 light_color = vec3(1.0);
    
    vec3 ambient = 0.2 * light_color;

    vec3 norm = normalize(Normal);
    vec3 light_dir = normalize(light_pos - FragPos);
    
	float diff = max(dot(norm, light_dir), 0.0);
    vec3 diffuse = diff * light_color;

    float specularStrength = 0.4;

    vec3 view_dir = normalize(view_pos - FragPos);
    vec3 reflect_dir = reflect(-light_dir, norm);
    
    float spec = pow(max(dot(view_dir, reflect_dir), 0.0), 64);

    vec3 specular = specularStrength * spec * light_color;

    vec3 result = (ambient + diffuse + specular) * object_color;

    FragColor = vec4(result, 1.0);
}