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
	
	_color = glm::vec3(
		static_cast<float>(rand()) / static_cast<float>(RAND_MAX),
		static_cast<float>(rand()) / static_cast<float>(RAND_MAX),
		static_cast<float>(rand()) / static_cast<float>(RAND_MAX)
	);

}

void Entity::update(float delta_time)
{
	_object->update(delta_time);
}

void Entity::draw(const ShaderProgram &program) const
{
	glm::mat4 model = glm::mat4(1.0f);

	model = glm::translate(model, _object->getPosition());
	model = glm::rotate(model, 0.0f, glm::vec3(1.0f));

	program.set_mat4("model", model);
	program.set_vec3("object_color", _color);
	
	_mesh->draw();
}

PhysicsObject *Entity::getPhysicsObject()
{
	return (_object);
}

void Entity::setPosition(const glm::vec3 &pos)
{
	_object->setPosition(pos);
}