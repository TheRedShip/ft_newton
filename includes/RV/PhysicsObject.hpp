/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhysicsObject.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheRed <TheRed@students.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:48:48 by TheRed            #+#    #+#             */
/*   Updated: 2025/05/24 14:48:48 by TheRed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NW_PHYSICSOBJECT__HPP
# define NW_PHYSICSOBJECT__HPP

# include "NW.hpp"

class PhysicsCollider;

class PhysicsObject 
{
	public:
		PhysicsObject(float mass);
		virtual ~PhysicsObject(void) = default;

		virtual void applyForce(const glm::vec3 &force) = 0;
		virtual void update(float deltaTime) = 0;

		virtual bool checkCollision(const PhysicsObject &other) const = 0;
		virtual void resolveCollision(PhysicsObject &other) = 0;

		const glm::vec3 &getPosition() const;
		const glm::vec3 &getVelocity() const;

		void setPosition(const glm::vec3 &position);
		void setVelocity(const glm::vec3 &velocity);
		void setMass(float mass);

		float getMass() const;

		PhysicsCollider *getCollider() const;

	protected:

		float 		_mass;

		glm::vec3	_position;
		glm::vec3	_velocity;
		glm::vec3	_acceleration;

		PhysicsCollider	*_collider;
};

#endif