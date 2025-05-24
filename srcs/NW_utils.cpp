/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT_utils.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:21:09 by TheRed            #+#    #+#             */
/*   Updated: 2025/03/17 11:54:25 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NW.hpp"

//0 output
std::vector<GLuint> generateTextures()
{
	std::vector<GLuint> textures(1);

	glGenTextures(1, textures.data());

	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, WIDTH, HEIGHT, 0, GL_RGBA, GL_FLOAT, NULL);
	glBindImageTexture(0, textures[0], 0, GL_FALSE, 0, GL_READ_WRITE, GL_RGBA32F);

	return (textures);
}

std::vector<Buffer *>	createDataOnGPU(Scene &scene)
{
	GLint max_gpu_size;
	glGetIntegerv(GL_MAX_SHADER_STORAGE_BLOCK_SIZE, &max_gpu_size);

	std::vector<Buffer *> buffers;
	
	buffers.push_back(new Buffer(Buffer::Type::UBO, 0, sizeof(GPUDebug), nullptr));

	return (buffers);
}

void	updateDataOnGPU(Scene &scene, std::vector<Buffer *> buffers)
{
	buffers[0]->update(&scene.getDebug(), sizeof(GPUDebug));
}
