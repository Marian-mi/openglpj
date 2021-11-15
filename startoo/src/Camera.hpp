#include "Renderer.h"
#include "vendors/GLM/glm.hpp"

class Camera {
private:
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 cameraFron = glm::vec3(0.0f, 0.0f, -1.0f);
	float mouseSensivity;
	float cameraSpeed;
public:
	Camera();
	~Camera();

	glm::mat4 GetView() {

	}
};