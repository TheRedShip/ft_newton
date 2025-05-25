/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NW.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:51:49 by TheRed            #+#    #+#             */
/*   Updated: 2025/03/30 16:56:56 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NW.hpp"

std::vector<GLuint>		generateTextures();

std::vector<Buffer *>	createDataOnGPU(Scene &scene);
void					updateDataOnGPU(Scene &scene, std::vector<Buffer *> buffers);

float cubeVertices[] = {
    // positions         // normals
    -0.5f,-0.5f, 0.5f,   0.0f,  0.0f,  1.0f,
     0.5f,-0.5f, 0.5f,   0.0f,  0.0f,  1.0f,
     0.5f, 0.5f, 0.5f,   0.0f,  0.0f,  1.0f,
     0.5f, 0.5f, 0.5f,   0.0f,  0.0f,  1.0f,
    -0.5f, 0.5f, 0.5f,   0.0f,  0.0f,  1.0f,
    -0.5f,-0.5f, 0.5f,   0.0f,  0.0f,  1.0f,
    // back face
    -0.5f,-0.5f,-0.5f,   0.0f,  0.0f, -1.0f,
    -0.5f, 0.5f,-0.5f,   0.0f,  0.0f, -1.0f,
     0.5f, 0.5f,-0.5f,   0.0f,  0.0f, -1.0f,
     0.5f, 0.5f,-0.5f,   0.0f,  0.0f, -1.0f,
     0.5f,-0.5f,-0.5f,   0.0f,  0.0f, -1.0f,
    -0.5f,-0.5f,-0.5f,   0.0f,  0.0f, -1.0f,
    // left face
    -0.5f, 0.5f, 0.5f,  -1.0f,  0.0f,  0.0f,
    -0.5f, 0.5f,-0.5f,  -1.0f,  0.0f,  0.0f,
    -0.5f,-0.5f,-0.5f,  -1.0f,  0.0f,  0.0f,
    -0.5f,-0.5f,-0.5f,  -1.0f,  0.0f,  0.0f,
    -0.5f,-0.5f, 0.5f,  -1.0f,  0.0f,  0.0f,
    -0.5f, 0.5f, 0.5f,  -1.0f,  0.0f,  0.0f,
    // right face
     0.5f, 0.5f, 0.5f,   1.0f,  0.0f,  0.0f,
     0.5f,-0.5f, 0.5f,   1.0f,  0.0f,  0.0f,
     0.5f,-0.5f,-0.5f,   1.0f,  0.0f,  0.0f,
     0.5f,-0.5f,-0.5f,   1.0f,  0.0f,  0.0f,
     0.5f, 0.5f,-0.5f,   1.0f,  0.0f,  0.0f,
     0.5f, 0.5f, 0.5f,   1.0f,  0.0f,  0.0f,
    // top face
    -0.5f, 0.5f,-0.5f,   0.0f,  1.0f,  0.0f,
    -0.5f, 0.5f, 0.5f,   0.0f,  1.0f,  0.0f,
     0.5f, 0.5f, 0.5f,   0.0f,  1.0f,  0.0f,
     0.5f, 0.5f, 0.5f,   0.0f,  1.0f,  0.0f,
     0.5f, 0.5f,-0.5f,   0.0f,  1.0f,  0.0f,
    -0.5f, 0.5f,-0.5f,   0.0f,  1.0f,  0.0f,
    // bottom face
    -0.5f,-0.5f,-0.5f,   0.0f, -1.0f,  0.0f,
     0.5f,-0.5f,-0.5f,   0.0f, -1.0f,  0.0f,
     0.5f,-0.5f, 0.5f,   0.0f, -1.0f,  0.0f,
     0.5f,-0.5f, 0.5f,   0.0f, -1.0f,  0.0f,
    -0.5f,-0.5f, 0.5f,   0.0f, -1.0f,  0.0f,
    -0.5f,-0.5f,-0.5f,   0.0f, -1.0f,  0.0f
};

int main(int argc, char **argv)
{
	std::string args = "";
	if (argc == 2)
		args = argv[1];

	Scene		scene;
	Window		window(&scene, WIDTH, HEIGHT, "Ft_newton", 0);
	
	glEnable(GL_DEPTH_TEST);
	// (optional) make sure you’re using the default depth func:
	glDepthFunc(GL_LESS);

	unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
    
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
 	glEnableVertexAttribArray(1);


	ShaderProgram program;
	
	Shader vertex_shader(GL_VERTEX_SHADER, "shaders/vertex.glsl");
	Shader fragment_shader(GL_FRAGMENT_SHADER, "shaders/frag.glsl");
	
	program.attachShader(&vertex_shader);
	program.attachShader(&fragment_shader);
	program.link();

	std::vector<GLuint> textures = generateTextures();
	std::vector<Buffer *> buffers = createDataOnGPU(scene);

	while (!window.shouldClose())
	{
		window.updateDeltaTime();
		
		updateDataOnGPU(scene, buffers);
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Camera *camera = scene.getCamera();

       	glm::mat4 view  = camera->getViewMatrix();
        glm::mat4 projection = glm::perspective(glm::radians(camera->getFov()), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
		
		program.use();

		program.set_mat4("view", view);
		program.set_mat4("projection", projection);
		
		program.set_vec3("light_dir", glm::vec3(0.5f, -1.0f, 0.0f));
		program.set_vec3("light_color", glm::vec3(1.0f, 1.0f, 1.0f));

        glm::mat4 model = glm::mat4(1.0f);
		program.set_mat4("model", model);
		program.set_vec3("object_color", glm::vec3(1.0f, 1.0f, 1.0f));

		glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);
		
		window.imGuiNewFrame();
		window.imGuiRender();

		window.display();
		window.pollEvents();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	return (0);
}
