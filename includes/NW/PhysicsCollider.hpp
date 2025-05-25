/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhysicsCollider.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheRed <TheRed@students.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:03:34 by TheRed            #+#    #+#             */
/*   Updated: 2025/05/25 16:03:34 by TheRed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NW_PHYSICSCOLLIDER__HPP
#define NW_PHYSICSCOLLIDER__HPP

#include "NW.hpp"

class Entity;

class PhysicsCollider
{
	public:
		PhysicsCollider(Entity *owner) : _owner(owner) {}
		
		virtual ~PhysicsCollider() = default;
		virtual bool intersects(const PhysicsCollider &other) const = 0;

	protected:
		Entity *_owner;

};

#endif