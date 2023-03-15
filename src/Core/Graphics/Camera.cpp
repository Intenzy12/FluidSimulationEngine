#include "Core/Graphics/Camera.h"
#include "Core/Engine.h"
#include "Core/MathConstants.h"
#include <math.h>

glm::mat4 Camera::projection = glm::mat4();
glm::mat4 Camera::translate = glm::mat4();
glm::vec3 Camera::position = glm::vec3();
glm::vec3 Camera::polarPosition = glm::vec3();
float Camera::fov = PI_F15 * 0.5f;
float Camera::nearPlane = 0.1f; 
float Camera::farPlane = 100.0f;

void Camera::init()
{
	const Engine::WindowData& windowData = Engine::GetInstance()->GetWindowData();
	float aspectRatio = windowData.width / windowData.height;
	projection = glm::perspective(fov, aspectRatio, nearPlane, farPlane);
}

void Camera::setPosition(const glm::vec3& ivec)
{
	position = ivec;

	polarPosition = {0.0, 0.0, 0.0};

	setRotation();
}

void Camera::setRotation()
{

	glm::vec3 center = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 up = glm::vec3(0.0f, 0.0f, 0.0f);

	translate = glm::lookAt(position, center, up);
}

void Camera::setPolarPosition(const glm::vec3& ivec)
{
	position.x = ivec.z * cos(ivec.x) * sin(ivec.y);
	position.y = ivec.z * sin(ivec.x) * sin(ivec.y);
	position.z = ivec.z * cos(ivec.y);

	polarPosition = ivec;

	setRotation();
}
