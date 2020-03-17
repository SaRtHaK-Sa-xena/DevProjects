#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include "Application.h"
#include "Camera.h"
#include <glm/mat4x4.hpp>

#include <glm/gtc/quaternion.hpp>


class ComputerGraphicsApp : public aie::Application {
public:

	ComputerGraphicsApp();
	virtual ~ComputerGraphicsApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:
	
	int increment = 0;
	glm::vec3 p;
	glm::quat r;

	//Camera
	Camera *myCamera = new Camera();

	// camera transforms
	glm::mat4	m_viewMatrix;
	glm::mat4	m_projectionMatrix;

	glm::vec3	m_positions[3];
	glm::quat	m_rotations[3];

	//move positions condition check
	bool decrementDown = false;
};