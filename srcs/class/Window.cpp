/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:16:24 by TheRed            #+#    #+#             */
/*   Updated: 2025/03/28 16:06:53 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.hpp"

void GLFWErrorCallback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error (%d): %s\n", error, description);
}

Window::Window(Scene *scene, int width, int height, const char *title, int sleep)
{
	_scene = scene;
	_fps = 0;

	glfwSetErrorCallback(GLFWErrorCallback);
	if (!glfwInit())
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		exit(-1);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	_window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!_window)
	{
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		glfwTerminate();
		exit(-1);
	}
	
	glfwMakeContextCurrent(_window);
	glfwSetWindowUserPointer(_window, this);

	glfwSetKeyCallback(_window, keyCallback);
	glfwSetCursorPosCallback(_window, mouseMoveCallback);
	glfwSetMouseButtonCallback(_window, mouseButtonCallback);

	gladLoadGL(glfwGetProcAddress);
	glfwSwapInterval(sleep);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO &io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(_window, true);
	ImGui_ImplOpenGL3_Init("#version 430");
}

Window::~Window(void)
{
	glfwTerminate();
}


void Window::process_input()
{
	bool forward = glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS;
	bool backward = glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS;
	bool left = glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS;
	bool right = glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS;
	bool up = glfwGetKey(_window, GLFW_KEY_SPACE) == GLFW_PRESS;
	bool down = glfwGetKey(_window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS;

	_scene->getCamera()->processKeyboard(forward, backward, left, right, up, down);
}

void Window::mouseMoveCallback(GLFWwindow* window, double xpos, double ypos)
{
	Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));
	(void) win; (void) xpos; (void) ypos;

	static double lastX = 0;
	static double lastY = 0;

	if (lastX == 0 && lastY == 0)
	{
		lastX = xpos;
		lastY = ypos;
	}

	double xoffset = xpos - lastX;
	double yoffset = lastY - ypos;

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) 
		win->_scene->getCamera()->processMouse(xoffset, yoffset, true);

	lastX = xpos;
	lastY = ypos;
}
void Window::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));
    (void) win; (void) button; (void) mods;
}
void Window::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));
    (void) win; (void) key; (void) scancode; (void) action; (void) mods;
	
	if (key == 67 && action == GLFW_PRESS)
	{
		glm::vec3 pos = win->_scene->getCamera()->getPosition();
		glm::vec2 dir = win->_scene->getCamera()->getDirection();

		std::cout << "\nCAM\t" << pos.x << " " << pos.y << " " << pos.z << "\t"
				<< dir.x << " " << dir.y << std::endl;
	}
}

void Window::updateDeltaTime()
{
	static double	lastTime = glfwGetTime();
	double			currentTime = glfwGetTime();
	
	_delta = currentTime - lastTime;

	lastTime = currentTime;
	_fps = 1.0f / _delta;
}

void Window::display()
{
    glfwSwapBuffers(_window);
}

void Window::pollEvents()
{
	this->process_input();
	_scene->getCamera()->update(_delta);
	
    glfwPollEvents();
}

bool Window::shouldClose()
{
    return glfwWindowShouldClose(_window);
}

void Window::imGuiNewFrame()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void Window::imGuiRender()
{
	bool has_changed = false;
	
	ImGui::Begin("Settings");

	ImGui::Text("Fps: %d", int(_fps));
	ImGui::Spacing();

	if (ImGui::CollapsingHeader("Camera"))
	{
		has_changed |= ImGui::SliderFloat("FOV", &_scene->getCamera()->getFov(), 1.0f, 180.0f);
	}

	if (ImGui::CollapsingHeader("Debug"))
	{
		if (ImGui::Checkbox("Enable", (bool *)(&_scene->getDebug().enabled)))
		{
			// raytracing_program.setDefine("DEBUG", std::to_string(_scene->getDebug().enabled));
			// raytracing_program.reloadShaders();
			has_changed = true;
		}
		ImGui::Separator();
		has_changed |= ImGui::SliderInt("Debug mode", &_scene->getDebug().mode, 0, 2);
	}

	ImGui::End();

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

GLFWwindow	*Window::getWindow(void) const
{
	return (_window);
}

float		Window::getFps(void) const
{
	return (_fps);
}
