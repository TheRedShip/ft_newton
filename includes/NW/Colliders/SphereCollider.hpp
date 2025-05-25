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
		SphereCollider(float radius);
		ColliderType getType() const override;
		
		float getRadius() const;

	private:
		float _radius;
};

#endif