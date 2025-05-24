/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Collider.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheRed <TheRed@students.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:55:41 by TheRed            #+#    #+#             */
/*   Updated: 2025/05/24 14:55:41 by TheRed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NW_COLLIDER__HPP
#define NW_COLLIDER__HPP

#include "NW.hpp"

class PhysicsObject;

class PhysicsCollider
{
	public:
		PhysicsCollider(PhysicsObject *owner) : _owner(owner) {}
		virtual ~PhysicsCollider() = default;

		/// Pure-geometry test, but can now pull extra info from owner
		virtual bool intersects(const PhysicsCollider &other) const = 0;

	protected:
	
		PhysicsObject *_owner;  // back-pointer to the object that “owns” this shape

};

#endif