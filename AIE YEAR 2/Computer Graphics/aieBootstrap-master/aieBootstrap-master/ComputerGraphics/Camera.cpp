#include "Camera.h"


Camera::Camera() : worldTransform(glm::mat4x4(1.0f)), viewTransform(glm::mat4x4(1.0f))
{
}

Camera::~Camera()
{
}

void Camera::updateProjectionViewTransform()
{
	//	translate the view transform int world transform
	worldTransform = glm::inverse(viewTransform);
	projectionViewTransform - projectionTransform * viewTransform;
}

void Camera::setPerspective(float fieldOfView, float aspectRatio, float near, float far)
{
									//fov in radians	
	worldTransform = glm::perspective(fieldOfView, aspectRatio, near, far);
}

void Camera::setLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up)
{
	viewTransform = glm::lookAt(from, to, up);

	////Position is known

	////	Calculate cameraDirection
	//// endPoint minus startPoint
	//// the normalize since we only need direction
	//glm::vec3 zAxis = glm::normalize(from - to);

	////	Get Positive right axis vector
	//glm::vec3 xAxis = glm::normalize(glm::cross(glm::normalize(up), zAxis));

	////	Calculate camera up vector
	//glm::vec3 yAxis = glm::cross(zAxis, xAxis);

	////	Create Translation and rotation matrix
	//// GLM accesses elements as mat[col][row] due to column-major layout
	//glm::mat4 translation = glm::mat4(1.0f); // Set to identity matrix by default
	//
	////	Third column, first row
	//translation[3][0] - from.x;
	//translation[3][1] - from.y;
	//translation[3][2] - from.z;

	//glm::mat4 rotation = glm::mat4(1.0f); //set to default

	////	First Column, first row
	//rotation[0][0] = xAxis.x;
	//rotation[1][0] = xAxis.y;
	//rotation[2][0] = xAxis.z;

	////	First Column, second row
	//rotation[0][1] = yAxis.x;
	//rotation[1][1] = yAxis.y;
	//rotation[2][1] = yAxis.z;

	////	First Column, third row
	//rotation[0][2] = zAxis.x;
	//rotation[1][2] = zAxis.y;
	//rotation[2][2] = zAxis.z;

	////Return lookAt mtarix as combination of translation and rotation matrix
	//return rotation * translation;

}

void Camera::setPosition(glm::vec3 position)
{
	viewTransform[3][0] = position.x;
	viewTransform[3][1] = position.y;
	viewTransform[3][2] = position.z;
}


