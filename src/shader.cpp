#include "shader.hpp"
#include "gl_utils.h"

#include <cstdint>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const std::string& vertexCode, const std::string& fragmentCode) 
{
    this->id = CreateShaderProgram(vertexCode.c_str(), fragmentCode.c_str());
}

BasicShader::BasicShader(const std::string& vertexCode, const std::string& fragmentCode) : Shader(vertexCode, fragmentCode)
	{
		getUniform(model_loc, "model");
		getUniform(texture_loc, "tex");
		getUniform(proj_loc, "proj");
		getUniform(view_loc, "view");
	}


void Shader::use() {
	glUseProgram(id);
}

void Shader::uniformMatrix(uint32_t loc, const glm::mat4 &matrix) {
    glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(matrix));
}

Shader::~Shader() {
	glDeleteProgram(id);
}

void Shader::getUniform(uint32_t &loc, const std::string &uniform_name) {
    loc = glGetUniformLocation(id, uniform_name.c_str());
}