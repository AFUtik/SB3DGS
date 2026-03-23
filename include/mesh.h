#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "point.h"
#include "shaders.h"
#include "gl_utils.h"

#include <vector>

class BasicShader;

class Mesh
{
protected:
    std::vector<Point> vertices;
    std::vector<unsigned int> indices;
    GLuint VAO, VBO, EBO;
    GLuint texture;

    uint32_t vertices_uploaded = 0;
    uint32_t indices_uploaded  = 0;
    glm::mat4 transform = glm::mat4(1.0f);
public:
    Mesh();
    virtual void Init();
    void Update();
    virtual void Render(BasicShader* shader);
    void Clear();

    void SetTexture(const char* filename);
    void AddPoint(Point point);
    void AddFace(unsigned int index_one, unsigned int index_two, unsigned int index_three);

};
//./SB3DGS
