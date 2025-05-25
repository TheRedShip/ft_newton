/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scene.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:29:41 by ycontre           #+#    #+#             */
/*   Updated: 2025/04/03 17:21:57 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scene.hpp"

Scene::Scene()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	_camera = new Camera(glm::vec3(0.0, 3.0, -20.0), glm::vec3(0., 1.0, 0.), 90.0f, 0.0f);

	_entity_manager = new EntityManager();

	_gpu_debug.enabled = 0;
	_gpu_debug.mode = 0;
}

Scene::~Scene()
{
	delete (_camera);
}

GPUDebug		&Scene::getDebug(void)
{
	return (_gpu_debug);
}

Camera			*Scene::getCamera(void) const
{
	return (_camera);
}

EntityManager	*Scene::getEntityManager(void)
{
	return (_entity_manager);
}