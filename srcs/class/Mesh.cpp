/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mesh.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheRed <TheRed@students.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:34:13 by TheRed            #+#    #+#             */
/*   Updated: 2025/05/25 16:34:13 by TheRed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mesh.hpp"

Mesh::Mesh(unsigned int VAO, unsigned int VBO, unsigned int vertex_count) : _VAO(VAO), _VBO(VBO), _vertex_count(vertex_count)
{

}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &_VAO);
	glDeleteBuffers(1, &_VBO);
}

void Mesh::draw() const
{
	glBindVertexArray(_VAO);
	glDrawArrays(GL_TRIANGLES, 0, _vertex_count);
	glBindVertexArray(0);
}

Mesh *Mesh::createBox(const glm::vec3 &size)
{
    float base_vertices[] = {
        // positions          // normals
        -0.5f,-0.5f, 0.5f,    0.0f, 0.0f, 1.0f,
         0.5f,-0.5f, 0.5f,    0.0f, 0.0f, 1.0f,
         0.5f, 0.5f, 0.5f,    0.0f, 0.0f, 1.0f,
         0.5f, 0.5f, 0.5f,    0.0f, 0.0f, 1.0f,
        -0.5f, 0.5f, 0.5f,    0.0f, 0.0f, 1.0f,
        -0.5f,-0.5f, 0.5f,    0.0f, 0.0f, 1.0f,
        // back
        -0.5f,-0.5f,-0.5f,    0.0f, 0.0f,-1.0f,
        -0.5f, 0.5f,-0.5f,    0.0f, 0.0f,-1.0f,
         0.5f, 0.5f,-0.5f,    0.0f, 0.0f,-1.0f,
         0.5f, 0.5f,-0.5f,    0.0f, 0.0f,-1.0f,
         0.5f,-0.5f,-0.5f,    0.0f, 0.0f,-1.0f,
        -0.5f,-0.5f,-0.5f,    0.0f, 0.0f,-1.0f,
        // left
        -0.5f, 0.5f, 0.5f,   -1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f,-0.5f,   -1.0f, 0.0f, 0.0f,
        -0.5f,-0.5f,-0.5f,   -1.0f, 0.0f, 0.0f,
        -0.5f,-0.5f,-0.5f,   -1.0f, 0.0f, 0.0f,
        -0.5f,-0.5f, 0.5f,   -1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.5f,   -1.0f, 0.0f, 0.0f,
        // right
         0.5f, 0.5f, 0.5f,    1.0f, 0.0f, 0.0f,
         0.5f,-0.5f, 0.5f,    1.0f, 0.0f, 0.0f,
         0.5f,-0.5f,-0.5f,    1.0f, 0.0f, 0.0f,
         0.5f,-0.5f,-0.5f,    1.0f, 0.0f, 0.0f,
         0.5f, 0.5f,-0.5f,    1.0f, 0.0f, 0.0f,
         0.5f, 0.5f, 0.5f,    1.0f, 0.0f, 0.0f,
        // top
        -0.5f, 0.5f,-0.5f,    0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f, 0.5f,    0.0f, 1.0f, 0.0f,
         0.5f, 0.5f, 0.5f,    0.0f, 1.0f, 0.0f,
         0.5f, 0.5f, 0.5f,    0.0f, 1.0f, 0.0f,
         0.5f, 0.5f,-0.5f,    0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f,-0.5f,    0.0f, 1.0f, 0.0f,
        // bottom
        -0.5f,-0.5f,-0.5f,    0.0f,-1.0f, 0.0f,
         0.5f,-0.5f,-0.5f,    0.0f,-1.0f, 0.0f,
         0.5f,-0.5f, 0.5f,    0.0f,-1.0f, 0.0f,
         0.5f,-0.5f, 0.5f,    0.0f,-1.0f, 0.0f,
        -0.5f,-0.5f, 0.5f,    0.0f,-1.0f, 0.0f,
        -0.5f,-0.5f,-0.5f,    0.0f,-1.0f, 0.0f
    };

    int count = 36;

    std::vector<float> vertices;
    vertices.reserve(count * 6);

    for (int i = 0; i < count; ++i)
    {
        glm::vec3 pos(base_vertices[i*6+0] * size.x,
                      base_vertices[i*6+1] * size.y,
                      base_vertices[i*6+2] * size.z);

        glm::vec3 norm(base_vertices[i*6+3],
                       base_vertices[i*6+4],
                       base_vertices[i*6+5]);

        vertices.insert(vertices.end(), {pos.x, pos.y, pos.z,
                                         norm.x, norm.y, norm.z});
    }

    unsigned int VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    return (new Mesh(VAO, VBO, count));
}
