/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:15:41 by TheRed            #+#    #+#             */
/*   Updated: 2025/03/17 12:02:16 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NW_WINDOW__HPP
# define NW_WINDOW__HPP

# include "NW.hpp"

class Scene;
class ShaderProgram;

class Window
{
	public:
		Window(Scene *scene, int width, int height, const char *title, int sleep);
		~Window(void);

		void		updateDeltaTime();
		void		display();
		void		pollEvents();
		bool		shouldClose();

		void		process_input();

		static void	keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
		static void	mouseMoveCallback(GLFWwindow *window, double xpos, double ypos);
		static void	mouseButtonCallback(GLFWwindow *window, int button, int action, int mods);

		void		imGuiNewFrame();
		void		imGuiRender();

		GLFWwindow	*getWindow(void) const;
		float		getFps(void) const;
		float		getDelta(void) const;


	private:
		GLFWwindow	*_window;
		Scene		*_scene;

		float		_fps;
		float		_delta;
};

#endif
