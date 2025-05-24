in vec3 Normal;
in vec3 FragPos;

out vec4 FragColor;

uniform vec3 light_dir;
uniform vec3 light_color;
uniform vec3 object_color;

void main()
{
    vec3 ambient = 0.2 * light_color;

    vec3 norm = normalize(Normal);
    vec3 light_dir_norm = normalize(-light_dir);
    
	float diff = max(dot(norm, light_dir_norm), 0.0);
    vec3 diffuse = diff * light_color;

    vec3 result = (ambient + diffuse) * object_color;
    FragColor = vec4(result, 1.0);
}