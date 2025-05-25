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

int main(int argc, char **argv)
{
	std::string args = "";
	if (argc == 2)
		args = argv[1];

	Scene		scene;
	Window		window(&scene, WIDTH, HEIGHT, "Ft_newton", 0);
	
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	ShaderProgram program;
	
	Shader vertex_shader(GL_VERTEX_SHADER, "shaders/vertex.glsl");
	Shader fragment_shader(GL_FRAGMENT_SHADER, "shaders/frag.glsl");
	
	program.attachShader(&vertex_shader);
	program.attachShader(&fragment_shader);
	program.link();

	std::vector<GLuint> textures = generateTextures();
	std::vector<Buffer *> buffers = createDataOnGPU(scene);

    Entity *cube_entity = new Entity(1.0f, Mesh::createCube(), new SphereCollider(1.0f));

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
		program.set_vec3("object_color", glm::vec3(1.0f, 1.0f, 1.0f));
        

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
