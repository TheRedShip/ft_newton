/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhysicsObject.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheRed <TheRed@students.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:50:07 by TheRed            #+#    #+#             */
/*   Updated: 2025/05/24 14:50:07 by TheRed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhysicsObject.hpp"

PhysicsObject::PhysicsObject(float mass) : _mass(mass), _position(0.0f), _velocity(0.0f), _acceleration(0.0f)
{

}

void PhysicsObject::applyForce(const glm::vec3 &force)
{
    _acceleration += force / _mass;
}

void PhysicsObject::update(float delta_time)
{
    _velocity += _acceleration * delta_time;
    _position += _velocity * delta_time;
    _acceleration = glm::vec3(0.0f);
}

const glm::vec3 &PhysicsObject::getPosition() const
{
    return (_position);
}

void PhysicsObject::setPosition(const glm::vec3 &pos)
{
    _position = pos;
}

const glm::vec3 &PhysicsObject::getVelocity() const
{
    return (_velocity);
}

void PhysicsObject::setVelocity(const glm::vec3 &vel)
{
    _velocity = vel;
}

float PhysicsObject::getMass() const
{
    return (_mass);
}

void PhysicsObject::setMass(float mass)
{
	_mass = mass;
}