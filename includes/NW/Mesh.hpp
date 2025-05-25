/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mesh.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheRed <TheRed@students.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:29:42 by TheRed            #+#    #+#             */
/*   Updated: 2025/05/25 16:29:42 by TheRed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NW_MESH_HPP
# define NW_MESH_HPP

# include "NW.hpp"

class Mesh
{
	public:
		Mesh(unsigned int VAO, unsigned int VBO, unsigned int vertex_count);
		~Mesh();

		void draw() const;

		static Mesh *createCube();
		// static std::shared_ptr<Mesh> createSphere(unsigned int segments = 16, unsigned int rings = 16);

	private:
		unsigned int _VAO;
		unsigned int _VBO;
		unsigned int _vertex_count;
};
#endif