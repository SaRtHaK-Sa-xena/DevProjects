#include "Camera.h"
#include <Input.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

const float defaultCameraSpeed = 10.f;

Camera::Camera()
{
	m_forwardKey = aie::INPUT_KEY_W;
	m_backKey = aie::INPUT_KEY_S;
	m_leftKey = aie::INPUT_KEY_A;
	m_rightKey = aie::INPUT_KEY_D;

	m_boost = aie::INPUT_KEY_LEFT_SHIFT;

	m_mouseLookButton = aie::INPUT_MOUSE_BUTTON_RIGHT;
}

Camera::~Camera()
{
}

void Camera::Update(float deltaTime)
{
	// quit if we press escape
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(m_forwardKey))
	{
		m_cameraPosition += m_cameraFront * m_cameraMoveSpeed * deltaTime;
	}

	if (input->isKeyDown(m_backKey))
	{
		m_cameraPosition -= m_cameraFront * m_cameraMoveSpeed * deltaTime;
	}

	if (input->isKeyDown(m_leftKey))
	{
		glm::vec3 dir = glm::normalize(glm::cross(m_cameraFront, m_cameraUp));
		m_cameraPosition -= dir * m_cameraMoveSpeed * deltaTime;
	}

	if (input->isKeyDown(m_rightKey))
	{
		glm::vec3 dir = glm::normalize(glm::cross(m_cameraFront, m_cameraUp));
		m_cameraPosition += dir * m_cameraMoveSpeed * deltaTime;
	}

	if (input->isMouseButtonDown(m_mouseLookButton))
	{
		int mouseXPos, mouseYPos;
		input->getMouseXY(&mouseXPos, &mouseYPos);

		float deltaMouseX = (float)mouseXPos - m_lastMouseXPos;
		float deltaMouseY = (float)mouseYPos - m_lastMouseYPos;

		m_cameraYaw += deltaMouseX;
		m_cameraPitch += deltaMouseY;

		if (m_cameraPitch > 85.0f)
			m_cameraPitch = 85.0f;
		if (m_cameraPitch < -85.0f)
			m_cameraPitch = -85.0f;

		CalculateFront();
	}


	// if shift held boost camera speed
	if (input->isKeyDown(m_boost))
	{
		m_cameraMoveSpeed += 0.5f;
	}
	// otherwise reset camera speed
	else
	{
		m_cameraMoveSpeed = defaultCameraSpeed;
	}
	
	m_viewMatrix = glm::lookAt(m_cameraPosition, m_cameraPosition + m_cameraFront, m_cameraUp);

	// record the current mouse position for use next frame.
	input->getMouseXY(&m_lastMouseXPos, &m_lastMouseYPos);

}

void Camera::CalculateFront()
{
	glm::vec3 front;
	front.x = glm::cos(glm::radians(m_cameraYaw)) * glm::cos(glm::radians(m_cameraPitch));
	front.y = glm::sin(glm::radians(m_cameraPitch));
	front.z = glm::sin(glm::radians(m_cameraYaw)) * glm::cos(glm::radians(m_cameraPitch));
	m_cameraFront = glm::normalize(front);
}

#pragma region Setters
void Camera::SetProjection(float fov, float aspect, float near, float far)
{
	m_projectionMatrix = glm::perspective(fov, aspect, near, far);
}
void Camera::SetPosition(const glm::vec3& pos)
{
	m_cameraPosition = pos;
}
void Camera::SetYawPitchRoll(float yaw, float pitch, float roll)
{
	m_cameraYaw = yaw;
	m_cameraPitch = pitch;
	m_cameraRoll = roll;

	CalculateFront();
}
#pragma endregion

#pragma region Getters
glm::vec3& Camera::GetPosition()
{
	return m_cameraPosition;
}
float Camera::GetYaw()
{
	return m_cameraYaw;
}
float Camera::GetPitch()
{
	return m_cameraPitch;
}
float Camera::GetRoll()
{
	return m_cameraRoll;
}
glm::vec3 Camera::GetFront()
{
	return m_cameraFront;
}
glm::mat4& Camera::GetView()
{
	return m_viewMatrix;
}
glm::mat4& Camera::GetProjection()
{
	return m_projectionMatrix;
}
glm::mat4 Camera::GetProjectionView()
{
	return m_projectionMatrix * m_viewMatrix;
}
#pragma endregion

#pragma region Movement
void Camera::Lookat(glm::vec3 target)
{
	glm::vec3 dir = glm::normalize(target - m_cameraPosition);
	m_cameraPitch = glm::degrees(glm::asin(dir.y));
	m_cameraYaw = glm::degrees(atan2(dir.y, dir.x));

	CalculateFront();
}

void Camera::SetMovementKeys(int forwardKey, int backKey, int leftKey, int rightKey, int a_boost)
{
	m_forwardKey = forwardKey;
	m_backKey = backKey;
	m_leftKey = leftKey;
	m_rightKey = rightKey;
	m_boost = a_boost;
}

void Camera::SetMouseLookButton(int mouseButton)
{
	m_mouseLookButton = mouseButton;
}
#pragma endregion

#pragma region UnderWork
//#include "Camera.h"
//
//
//Camera::Camera() : worldTransform(glm::mat4x4(1.0f)), viewTransform(glm::mat4x4(1.0f))
//{
//}
//
//Camera::~Camera()
//{
//}
//
//void Camera::updateProjectionViewTransform()
//{
//	//	translate the view transform int world transform
//	worldTransform = glm::inverse(viewTransform);
//	projectionViewTransform - projectionTransform * viewTransform;
//}
//
//void Camera::setPerspective(float fieldOfView, float aspectRatio, float near, float far)
//{
//									//fov in radians	
//	worldTransform = glm::perspective(fieldOfView, aspectRatio, near, far);
//}
//
//void Camera::setLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up)
//{
//	viewTransform = glm::lookAt(from, to, up);
//
//	////Position is known
//
//	////	Calculate cameraDirection
//	//// endPoint minus startPoint
//	//// the normalize since we only need direction
//	//glm::vec3 zAxis = glm::normalize(from - to);
//
//	////	Get Positive right axis vector
//	//glm::vec3 xAxis = glm::normalize(glm::cross(glm::normalize(up), zAxis));
//
//	////	Calculate camera up vector
//	//glm::vec3 yAxis = glm::cross(zAxis, xAxis);
//
//	////	Create Translation and rotation matrix
//	//// GLM accesses elements as mat[col][row] due to column-major layout
//	//glm::mat4 translation = glm::mat4(1.0f); // Set to identity matrix by default
//	//
//	////	Third column, first row
//	//translation[3][0] - from.x;
//	//translation[3][1] - from.y;
//	//translation[3][2] - from.z;
//
//	//glm::mat4 rotation = glm::mat4(1.0f); //set to default
//
//	////	First Column, first row
//	//rotation[0][0] = xAxis.x;
//	//rotation[1][0] = xAxis.y;
//	//rotation[2][0] = xAxis.z;
//
//	////	First Column, second row
//	//rotation[0][1] = yAxis.x;
//	//rotation[1][1] = yAxis.y;
//	//rotation[2][1] = yAxis.z;
//
//	////	First Column, third row
//	//rotation[0][2] = zAxis.x;
//	//rotation[1][2] = zAxis.y;
//	//rotation[2][2] = zAxis.z;
//
//	////Return lookAt mtarix as combination of translation and rotation matrix
//	//return rotation * translation;
//
//}
//
//void Camera::setPosition(glm::vec3 position)
//{
//	viewTransform[3][0] = position.x;
//	viewTransform[3][1] = position.y;
//	viewTransform[3][2] = position.z;
//}
#pragma endregion UnderWork