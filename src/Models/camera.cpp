#include "camera.h"

Camera::Camera()
{
	position = glm::vec3(0, 1, -2);
	fov = 60;
	aspect = WINDOW_WIDTH/WINDOW_HEIGHT;
	nearPlane = 0.01f;
	farPlane = 200;
	yaw = 180;
	pitch = 0;
	ortho = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 1.0f);
}

glm::mat4 Camera::getProjectionMatrix() 
{
    return glm::perspective(glm::radians(fov), aspect, nearPlane, farPlane);
}

const glm::mat4& Camera::getOrtho() 
{
    return ortho;
}

glm::mat4 Camera::getViewMatrix() 
{
	glm::mat4 rotY = glm::rotate(glm::mat4(1.0f), glm::radians(yaw), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 rotX = glm::rotate(glm::mat4(1.0f), glm::radians(pitch), glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 trans = glm::translate(glm::mat4(1.0f), -position);
	return rotX * rotY * trans;
}
