#pragma once

#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

class Camera
{
public:

	Camera();
	virtual ~Camera();

	virtual void Update(float deltaTime);

#pragma region Setter
	void SetPosition(const glm::vec3 &pos);
	void SetYawPitchRoll(float yaw, float pitch, float roll);
	void SetProjection(float fov, float aspect, float near, float far);
#pragma endregion

#pragma region Getter
	glm::vec3& GetPosition();

	float GetYaw();
	float GetPitch();
	float GetRoll();

	glm::vec3 GetFront();

	glm::mat4& GetView();
	glm::mat4& GetProjection();
	glm::mat4 GetProjectionView();
#pragma endregion
	
#pragma region Movement
	void Lookat(glm::vec3 target);

	void SetMovementKeys(int forwardKey, int backKey, int leftKey, int rightKey);
	void SetMouseLookButton(int mouseButton);
#pragma endregion

protected:

	void CalculateFront();

	// camera transforms
	glm::mat4	m_viewMatrix;				// Matrix that defines how the camera views for OpenGL
	glm::mat4	m_projectionMatrix;

	// movement keys
	int m_forwardKey;	// defaults to W
	int m_backKey;		// defaults to S
	int m_leftKey;		// defaults to A
	int m_rightKey;		// defaults to D

	int m_mouseLookButton;					// defaults to right mouse button

private:
	glm::vec3 m_cameraPosition = glm::vec3(0, 2, -2);
	glm::vec3 m_cameraFront = glm::vec3(0, 0, 1);
	glm::vec3 m_cameraUp = glm::vec3(0, 1, 0);			// Camera orientation so it is always facing up

	float m_cameraYaw = 0.0f;				// Left/Right rotation for view
	float m_cameraPitch = 0.0f;				// Up/Down rotation for view
	float m_cameraRoll = 0.0f;				// Rotating the orientation of the view

	int m_lastMouseXPos, m_lastMouseYPos;	// Record of previous mouse position for distance calculations

	float m_cameraMoveSpeed = 10.0f;
};

