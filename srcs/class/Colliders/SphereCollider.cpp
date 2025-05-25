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

SphereCollider::SphereCollider(float radius) : _radius(radius)
{

}

ColliderType SphereCollider::getType() const
{
	return (ColliderType::SPH);
}

float SphereCollider::getRadius() const
{
	return (_radius);
}
