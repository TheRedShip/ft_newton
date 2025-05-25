/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BoxCollider.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheRed <TheRed@students.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 21:26:19 by TheRed            #+#    #+#             */
/*   Updated: 2025/05/25 21:26:19 by TheRed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NW_COLLIDERS_BOXCOLLIDER_HPP
# define NW_COLLIDERS_BOXCOLLIDER_HPP

# include "NW.hpp"

class BoxCollider : public PhysicsCollider
{
	public:
		BoxCollider(const glm::vec3 &size) : _size(size) {}
		ColliderType getType() const override { return ColliderType::BOX; }

		const glm::vec3 &getSize() const { return _size; }

	private:
		glm::vec3 _size;
};

#endif