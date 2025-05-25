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
#define NW_ENTITY__HPP

#include "NW.hpp"

class Entity
{
	public:
		Entity(float mass, Mesh *mesh, PhysicsCollider *collider);

		void update(float delta_time);

		void draw(const ShaderProgram &program) const;

	private:
		PhysicsObject	_object;
		Mesh			*_mesh;
		PhysicsCollider	*_collider;


}

#endif