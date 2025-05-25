/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SphereCollider.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheRed <TheRed@students.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:24:30 by TheRed            #+#    #+#             */
/*   Updated: 2025/05/25 16:24:30 by TheRed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colliders/SphereCollider.hpp"

SphereCollider::SphereCollider(Entity *owner, float radius) : PhysicsCollider(owner), _radius(radius)
{

}

float SphereCollider::getRadius() const
{
	return _radius;
}

// bool SphereCollider::intersects(const PhysicsCollider &other)
// {
//     if (auto *sphere = dynamic_cast<const SphereCollider *>(&other))
// 	{
//         float dist2 = glm::length2(_owner - posB);
//         float radSum = radius + sphere->radius;
//         return dist2 <= radSum * radSum;
//     }
//     return false;
// }