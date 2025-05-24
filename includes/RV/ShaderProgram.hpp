/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShaderProgram.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:22:17 by TheRed            #+#    #+#             */
/*   Updated: 2025/03/17 12:01:36 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NW_SHADERPROGRAM_HPP
# define NW_SHADERPROGRAM_HPP

# include "NW.hpp"

class Shader;

class ShaderProgram
{
	public:
		ShaderProgram();
		~ShaderProgram(void);

		void	attachShader(Shader *shader);
		void	clearShaders();
		
		void	link(void);
		
		void	use(void);
		void	dispathCompute(GLuint x, GLuint y, GLuint z);
		
		void	bindImageTexture(GLuint texture_id, GLuint unit, GLenum access, GLenum format) const;

		void	watchForChanges(void);
		void	reloadShaders(void);

		void	set_int(const std::string &name, int value) const;
		void	set_float(const std::string &name, float value) const;
		void	set_vec2(const std::string &name, const glm::vec2 &value) const;
		void	set_ivec2(const std::string &name, const glm::ivec2 &value) const;
		void	set_vec3(const std::string &name, const glm::vec3 &value) const;
		void	set_mat4(const std::string &name, const glm::mat4 &value) const;



		void	set_textures(std::map<std::string, std::vector<GLuint>> texture_ids);

		void	setDefine(const std::string &name, const std::string &value);

		GLuint	getProgram(void) const;

	private:
		std::vector<Shader *>	_shaders;
		GLuint					_program;
};

#endif
