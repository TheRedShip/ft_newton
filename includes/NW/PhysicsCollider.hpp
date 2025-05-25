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

enum class ColliderType
{
    SPH,
    BOX,
};

class PhysicsCollider
{
	public:
		virtual ~PhysicsCollider() = default;
		virtual ColliderType getType() const = 0;
};

#endif