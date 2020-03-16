#pragma once
#include "Camera.h"

#include <Input.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

class FlyCamera : public Camera
{
private:
	float m_speed;
	glm::vec3 up = glm::vec3(0,1,0);
	glm::vec3 forward = glm::vec3(0, 0, 1);
	glm::vec3 backward = glm::vec3(0, 0, -1);

public:
	//	Update each frame
	void update(float deltaTime);
	
	//	Set camera moves
	void setSpeed(float speed) { m_speed = speed; };

protected:	
	aie::Input* m_input;

	//movement
	int m_forwardKey,	//Default to W
		m_backwardKey,	//Default to S
		m_leftKey,		//Default to A
		m_rightKey,		//Default to D
		m_mouseButton;	//Default to RMB
};

