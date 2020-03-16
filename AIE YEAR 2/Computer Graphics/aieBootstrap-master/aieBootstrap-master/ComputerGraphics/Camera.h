#pragma once
#include <glm/glm.hpp>
#include <glm/ext.hpp>

class Camera
{
private:

	//	the transform applied to the world
	glm::mat4 worldTransform;
	
	//	the transform of the camera
	glm::mat4 viewTransform;

	//	projection transform 
	glm::mat4 projectionTransform;

	//	Drawn from the current projection
	glm::mat4 projectionViewTransform;

	void updateProjectionViewTransform();

public:

	Camera();
	~Camera();

	//	update each frame
	virtual void update(float deltaTime);

	//	Set perspective manually
	void setPerspective(float fieldOfView, float aspectRatio, float near, float far);
	void setLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up);
	void setPosition(glm::vec3 position);

	//	Getters for private variables of camera
	glm::mat4 getWorldTransform() { return worldTransform; };
	glm::mat4 getView() { return viewTransform; };
	glm::mat4 getProjection() { return projectionTransform; };
	glm::mat4 getProjectionView() { return projectionViewTransform; };
};

