#pragma once

#include "constants.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:

glm::vec3 position;
glm::vec3 front;
glm::vec3 up;
glm::mat4 ortho;
 
float fov;
float aspect;
float nearPlane;
float farPlane;
float yaw;
float pitch;

Camera();

glm::mat4 getProjectionMatrix();
glm::mat4 getViewMatrix();
const glm::mat4& getOrtho();

};
