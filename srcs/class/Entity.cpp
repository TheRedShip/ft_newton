/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheRed <TheRed@students.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:40:41 by TheRed            #+#    #+#             */
/*   Updated: 2025/05/25 16:40:41 by TheRed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.hpp"

Entity::Entity(float mass, Mesh *mesh, PhysicsCollider *collider) : _mesh(mesh), _collider(collider)
{
	_object = new PhysicsObject(mass);
}

void Entity::update(float delta_time)
{
	_object->update(delta_time);
}

void Entity::draw(const ShaderProgram &program) const
{
	glm::mat4 model = glm::translate(glm::mat4(1.0f), _object->getPosition());

	program.set_mat4("model", model);
	
	_mesh->draw();
}

PhysicsObject *Entity::getPhysicsObject()
{
	return (_object);
}