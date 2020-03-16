#define GLM_ENABLE_EXPERIMENTAL
#include "ComputerGraphicsApp.h"
#include "Gizmos.h"
#include "Input.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtx/transform.hpp>



using glm::vec3;
using glm::vec4;
using glm::mat4;
using aie::Gizmos;

ComputerGraphicsApp::ComputerGraphicsApp() {

}

ComputerGraphicsApp::~ComputerGraphicsApp() {

}

bool ComputerGraphicsApp::startup() {
	
	setBackgroundColour(0.25f, 0.25f, 0.25f);

	// initialise gizmo primitive counts
	Gizmos::create(10000, 10000, 10000, 10000);
	
	// Camera Initialize
	myCamera->Lookat(glm::vec3(10));
	//myCamera->SetPosition(glm::vec3(0));
	//myCamera->SetYawPitchRoll(myCamera->GetYaw(), myCamera->GetPitch(), myCamera->GetRoll());
	myCamera->SetProjection(glm::pi<float>() * 0.25f, 16.0f / 9.0f, 0.1f, 1000.0f);

	// create simple camera transforms
	m_viewMatrix = glm::lookAt(vec3(10), vec3(0), vec3(0, 1, 0));
	m_projectionMatrix = glm::perspective(glm::pi<float>() * 0.25f, 16.0f / 9.0f, 0.1f, 1000.0f);
		//m_viewMatrix = glm::inverse(m_viewMatrix);

	//Quaternions Tutorial
	m_positions[0] = glm::vec3(10, 5, 10);
	m_positions[1] = glm::vec3(-10, 5, -10);

	m_rotations[0] = glm::quat(glm::vec3(0, -1, 0));
	m_rotations[1] = glm::quat(glm::vec3(0, 1, 0));


	return true;
}

void ComputerGraphicsApp::shutdown() {

	Gizmos::destroy();
}

void ComputerGraphicsApp::update(float deltaTime) {

	// wipe the gizmos clean for this frame
	Gizmos::clear();

	// draw a simple grid with gizmos
	vec4 white(1);
	vec4 black(0, 0, 0, 1);
	for (int i = 0; i < 21; ++i) {
		Gizmos::addLine(vec3(-10 + i, 0, 10),
						vec3(-10 + i, 0, -10),
						i == 10 ? white : black);
		Gizmos::addLine(vec3(10, 0, -10 + i),
						vec3(-10, 0, -10 + i),
						i == 10 ? white : black);
	}

	#pragma region Quaternion

	//	use time to animate a value between [0,1]
	float s = glm::cos(getTime()) * 0.5f + 0.5f;

	//	standard linear interpolation
	glm::vec3 p = (1.0f - s) * m_positions[0] + s * m_positions[1];

	//	quaternion slerp
	glm::quat r = glm::slerp(m_rotations[0], m_rotations[0], s);

	//	build a matrix
	glm::mat4 m = glm::translate(p) * glm::toMat4(r);

	//	draw a transform and box
	Gizmos::addTransform(m);
	Gizmos::addAABBFilled(p, glm::vec3(.5f), glm::vec4(1, 0, 0, 1), &m);

	#pragma endregion Animated Box

	// add a transform so that we can see the axis
	Gizmos::addTransform(mat4(1));

	// quit if we press escape
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	{
		quit();
	}

	//	update camera
	myCamera->Update(deltaTime);

	//====Zoom in on angle
	//m_viewMatrix = glm::inverse(m_viewMatrix);

	// what happens here?

	//m_viewMatrix = m_viewMatrix + glm::translate(m_viewMatrix, glm::vec3(m_viewMatrix[2].x, m_viewMatrix[2].y, m_viewMatrix[2].z)*0.1f);

	//====Zoom out on angle
	/*m_viewMatrix = glm::inverse(m_viewMatrix);

	m_viewMatrix = m_viewMatrix - deltaTime * glm::translate(m_viewMatrix, glm::vec3(m_viewMatrix[3].x, m_viewMatrix[3].y, m_viewMatrix[3].z));*/
}

void ComputerGraphicsApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// update perspective based on screen size
	//m_projectionMatrix = glm::perspective(glm::pi<float>() * 0.25f, getWindowWidth() / (float)getWindowHeight(), 0.1f, 1000.0f);

	//Gizmos::draw(m_projectionMatrix * m_viewMatrix);
	Gizmos::draw(myCamera->GetProjectionView());
}