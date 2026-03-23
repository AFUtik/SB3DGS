#pragma once

#include <string>
#include <glm/glm.hpp>

class Shader {
	uint32_t id;
public:
	Shader(const std::string& vertexCode, const std::string& fragmentCode);
	~Shader();

	void getUniform(uint32_t &loc, const std::string &uniform_name);

	void uniformMatrix(uint32_t model_loc, const glm::mat4 &matrix);
	void use();
};

class BasicShader : public Shader {
public:
	BasicShader(const std::string& vertexCode, const std::string& fragmentCode);

	uint32_t model_loc;
	uint32_t texture_loc;
	uint32_t proj_loc;
	uint32_t view_loc;
};

extern uint32_t compile_shaders_file(const std::string& vertexFile, const std::string& fragmentFile);
extern uint32_t compile_shaders_code(const std::string& vertexCode, const std::string& fragmentCode);