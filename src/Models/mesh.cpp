#include "mesh.h"
#include "shader.hpp"

Mesh::Mesh()
{
	
}

void Mesh::Init()
{
    size_t vert_size = vertices.capacity();
    size_t ind_size  = indices.capacity();

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vert_size * sizeof(Point), vertices.data(), GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, ind_size * sizeof(unsigned int), indices.data(), GL_DYNAMIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Point), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Point), (void*)(offsetof(Point, u)));
    glEnableVertexAttribArray(1);

    vertices_uploaded = vert_size;
    indices_uploaded = ind_size;
}

void Mesh::Update()
{
    glBindVertexArray(VAO);
    if(vertices.size() > vertices_uploaded) {
        size_t vert_size = vertices.capacity();
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vert_size * sizeof(Point), vertices.data(), GL_DYNAMIC_DRAW);
        vertices_uploaded = vert_size;
    } else {
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(Point), vertices.data());
    }

    if(indices.size() > indices_uploaded) {
        size_t ind_size = indices.capacity();
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, ind_size * sizeof(Point), indices.data(), GL_DYNAMIC_DRAW);
        indices_uploaded = ind_size;
    } else {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, indices.size() * sizeof(unsigned int), indices.data());
    }
    glBindVertexArray(0);
}

void Mesh::Render(BasicShader* shader)
{
    shader->uniformMatrix(shader->model_loc, this->transform);

    glActiveTexture(GL_TEXTURE0 + 0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glUniform1i(shader->texture_loc, 0);

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Mesh::SetTexture(const char* filename)
{
    texture = CreateTexture(filename);
}

void Mesh::Clear()
{
    vertices.clear();
    indices.clear();
}

void Mesh::AddPoint(Point point)
{vertices.push_back(point);}

void Mesh::AddFace(unsigned int index_one, unsigned int index_two, unsigned int index_three)
{
    indices.push_back(index_one);
    indices.push_back(index_two);
    indices.push_back(index_three);
}
