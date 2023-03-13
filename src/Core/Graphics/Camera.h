#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/projection.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera {
public: 
	Camera();
	~Camera();
	
	static void init();
	static void setPosition(const glm::vec3& ivec);
	static void setPolarPosition(const glm::vec3& ivec);
	static void setRotation();

private:
	static glm::mat4 projection;
	static glm::mat4 translate;
	static glm::vec3 position;
	static glm::vec3 polarPosition;

	static float fov;
	static float nearPlane;
	static float farPlane;
};
