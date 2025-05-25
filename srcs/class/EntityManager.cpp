/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityManager.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheRed <TheRed@students.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 21:46:00 by TheRed            #+#    #+#             */
/*   Updated: 2025/05/25 21:46:00 by TheRed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EntityManager.hpp"

EntityManager::~EntityManager()
{
	for (Entity *entity : _entities)
		delete entity;
}

void EntityManager::addEntity(Entity *entity)
{
	if (entity)
		_entities.push_back(entity);
}

void EntityManager::removeEntity(Entity *entity)
{
	if (entity)
	{
		auto it = std::find(_entities.begin(), _entities.end(), entity);
		if (it != _entities.end())
		{
			delete *it;
			_entities.erase(it);
		}
	}
}

void EntityManager::updateEntities(float delta_time)
{
	for (Entity *entity : _entities)
	{
		if (!entity)
			continue;

		entity->update(delta_time);
	}
}

void EntityManager::drawEntities(const ShaderProgram &program) const
{
	for (const Entity *entity : _entities)
	{
		if (entity)
			entity->draw(program);
	}
}