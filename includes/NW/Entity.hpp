/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheRed <TheRed@students.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:06:34 by TheRed            #+#    #+#             */
/*   Updated: 2025/05/24 15:06:34 by TheRed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NW_ENTITY__HPP
# define NW_ENTITY__HPP

# include "NW.hpp"

class Mesh;
class PhysicsCollider;
class PhysicsObject;

class Entity
{
	public:
		Entity(float mass, Mesh *mesh, PhysicsCollider *collider);

		void update(float delta_time);
		void draw(const ShaderProgram &program) const;

		PhysicsObject *getPhysicsObject();

		void setPosition(const glm::vec3 &pos);

	private:
		PhysicsObject	*_object;
		Mesh			*_mesh;
		PhysicsCollider	*_collider;

		glm::vec3		_color;
};

#endif