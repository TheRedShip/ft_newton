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
		PhysicsObject(void) = default;

		void applyForce(const glm::vec3 &force);
		void update(float deltaTime);

		const glm::vec3 &getPosition() const;
		const glm::vec3 &getVelocity() const;

		void setPosition(const glm::vec3 &position);
		void setVelocity(const glm::vec3 &velocity);
		void setMass(float mass);

		float getMass() const;

	protected:

		float 		_mass;

		glm::vec3	_position;
		glm::vec3	_velocity;
		glm::vec3	_acceleration;
};

#endif