/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityManager.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheRed <TheRed@students.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 21:45:16 by TheRed            #+#    #+#             */
/*   Updated: 2025/05/25 21:45:16 by TheRed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NW_ENTITYMANAGER__HPP
# define NW_ENTITYMANAGER__HPP

# include "NW.hpp"

class Entity;

class EntityManager
{
	public:
		EntityManager() = default;
		~EntityManager();

		void addEntity(Entity *entity);
		void removeEntity(Entity *entity);
		void updateEntities(float delta_time);
		void drawEntities(const ShaderProgram &program) const;

	private:
		std::vector<Entity *> _entities;
};

#endif