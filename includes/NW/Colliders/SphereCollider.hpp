/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SphereCollider.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheRed <TheRed@students.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:21:28 by TheRed            #+#    #+#             */
/*   Updated: 2025/05/25 16:21:28 by TheRed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NW_COLLIDERS_SPHERECOLLIDER_HPP
# define NW_COLLIDERS_SPHERECOLLIDER_HPP

# include "NW.hpp"

class SphereCollider : public PhysicsCollider
{
	public:
		SphereCollider(float radius) : _radius(radius) {}
		ColliderType getType() const override { return ColliderType::SPH; }
		
		float getRadius() const { return _radius; }

	private:
		float _radius;
};

#endif