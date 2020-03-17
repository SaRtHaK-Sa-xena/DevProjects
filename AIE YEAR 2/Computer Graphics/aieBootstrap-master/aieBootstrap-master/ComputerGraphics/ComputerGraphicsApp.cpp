#define GLM_ENABLE_EXPERIMENTAL
#include "ComputerGraphicsApp.h"
#include <iostream>
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

	//Quaternions Tutorial---PART 1
	m_positions[0] = glm::vec3(10, 5, 10);
	m_positions[1] = glm::vec3(-10, 5, -10);
	m_positions[2] = glm::vec3(-20, 5, -10);

	m_rotations[0] = glm::quat(glm::vec3(0, -1, 0));
	m_rotations[1] = glm::quat(glm::vec3(0, 1, 0));
	m_rotations[2] = glm::quat(glm::vec3(1, 0, 0));
	//Quaternions Tutorial---PART 1

	//Quaternions Tutorial---PART 2
	m_hipFrames[0].position = glm::vec3(0, 5, 0);
	m_hipFrames[0].rotation = glm::quat(glm::vec3(1, 0, 0));
	m_hipFrames[1].position = glm::vec3(0, 5, 0);
	m_hipFrames[1].rotation = glm::quat(glm::vec3(-1, 0, 0));

	m_kneeFrames[0].position = glm::vec3(0, -2.5, 0);
	m_kneeFrames[0].rotation = glm::quat(glm::vec3(1, 0, 0));
	m_kneeFrames[1].position = glm::vec3(0, 2.5, 0);
	m_kneeFrames[1].rotation = glm::quat(glm::vec3(0, 0, 0));

	m_ankleFrames[0].position = glm::vec3(0, -2.5, 0);
	m_ankleFrames[0].rotation = glm::quat(glm::vec3(-1, 0, 0));
	m_ankleFrames[1].position = glm::vec3(0, -2.5, 0);
	m_ankleFrames[1].rotation = glm::quat(glm::vec3(0, 0, 0));

	//Quaternions Tutorial---PART 2

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
	//	using consine value to get a value between -1,0, and 1

	//value to move position and rotation to



	
	//Check if decrementDown needs to be modified\
	//	If at end point
	//if (increment == m_positions->length())
	//{
	//	//	Start to decrement down
	//	decrementDown = true;
	//}
	//if(increment == 0)
	//{
	//	//	Increment up
	//	decrementDown = false;
	//}

	////If value at max
	//if (s > 0.997)
	//{
	//	// Change the position to go to next
	//	if (decrementDown)
	//		increment--;
	//	else
	//		increment++;
	//}
	////	If at end
	//if (decrementDown)
	//{
	//	//	standard linear interpolation
	//	p = (1.0f - s) * m_positions[increment] + s * m_positions[increment - 1];

	//	//	quaternion slerp //==Box's rotation from one point to another
	//	r = glm::slerp(m_rotations[increment], m_rotations[increment - 1], s);
	//}
	//else
	//{
	//	//	standard linear interpolation
	//	p = (1.0f - s) * m_positions[increment] + s * m_positions[increment + 1];

	//	//	quaternion slerp //==Box's rotation from one point to another
	//	r = glm::slerp(m_rotations[increment], m_rotations[increment + 1], s);
	//}
	
	//	time allocated to move between points
	//s = glm::cos(getTime()) * 0.5f + 0.5f;


	////	Distance Check
	//if (glm::distance(p, m_positions[increment + scalar]) < 1)
	//{
	//	std::cout << "Close To It" << std::endl;
	//	
	//	//	If incremented all the way to the end
	//	if (increment == m_positions->length()-1)
	//	{
	//		scalar = -1;
	//	}
	//	if (increment == 0)
	//	{
	//		scalar = 1;
	//	}

	//	// Add to increment
	//	increment += scalar;
	//}
	if (start)
	{
		s += deltaTime;

		//if (increment == 0)
		//{
		//	scalar = 1;
		//	//std::cout << "GO FORWARD" << std::endl;
		//}
		////	If incremented all the way to the end
		//else if (increment == m_positions->length() - 1)
		//{
		//	//std::cout << "GO BACK" << std::endl;
		//	scalar = -1;
		//}

		if (s >= 1.f)
		{
			s = 0.f;

			//	// Add to increment
			//increment += scalar;
			if (forward) {
				increment += 1;
			}
			else {
				increment -= 1;
			}
		}

		if (increment >= 2)
		{
			increment = 2;
			//atEnd = true;
			forward = false;
		}
		if (increment <= 0)
		{
			increment = 0;
			forward = true;
			//atEnd = false;
		}

		//	call movement
		std::cout << "===========" << std::endl;
		std::cout << "Scalar: " << scalar << std::endl;
		std::cout << "Increment: " << increment << std::endl;
		std::cout << "===========" << std::endl;


		// if forward -> if (increment = 1) -> increment, increment + 1
		if (forward)
		{
			if (increment == 0)
			{
				//	standard linear interpolation
				p = (1.0f - s) * m_positions[increment] + s * m_positions[increment + 1];

				//	quaternion slerp //==Box's rotation from one point to another
				r = glm::slerp(m_rotations[increment], m_rotations[increment + 1], s);
			}
			if (increment == 1)
			{
				//	standard linear interpolation
				p = (1.0f - s) * m_positions[increment] + s * m_positions[increment + 1];

				//	quaternion slerp //==Box's rotation from one point to another
				r = glm::slerp(m_rotations[increment], m_rotations[increment + 1], s);
			}
			if (increment == 2)
			{
				//	standard linear interpolation
				p = (1.0f - s) * m_positions[increment] + s * m_positions[increment + 1];

				//	quaternion slerp //==Box's rotation from one point to another
				r = glm::slerp(m_rotations[increment], m_rotations[increment + 1], s);
			}
		}
		else
		{
			if (increment == 0)
			{
				//	standard linear interpolation
				p = (1.0f - s) * m_positions[increment] + s * m_positions[increment - 1];

				//	quaternion slerp //==Box's rotation from one point to another
				r = glm::slerp(m_rotations[increment], m_rotations[increment - 1], s);
			}
			if (increment == 1)
			{
				//	standard linear interpolation
				p = (1.0f - s) * m_positions[increment] + s * m_positions[increment - 1];

				//	quaternion slerp //==Box's rotation from one point to another
				r = glm::slerp(m_rotations[increment], m_rotations[increment - 1], s);
			}
			if (increment == 2)
			{
				//	standard linear interpolation
				p = (1.0f - s) * m_positions[increment] + s * m_positions[increment - 1];

				//	quaternion slerp //==Box's rotation from one point to another
				r = glm::slerp(m_rotations[increment], m_rotations[increment - 1], s);
			}
		}

		//	build a matrix
		glm::mat4 m = glm::translate(p) * glm::toMat4(r);

		//	draw a transform and box
		Gizmos::addTransform(m);
		Gizmos::addAABBFilled(p, glm::vec3(.5f), glm::vec4(1, 0, 0, 1), &m);

	}
	#pragma endregion Animated Box
	

	#pragma region Leg Animation
	
	//	animate leg
	float s = glm::cos(getTime()) * 0.5f + 0.5f;

	//	linearly interpolate position
	glm::vec3 p = (1.0f - s) * m_hipFrames[0].position + s * m_hipFrames[1].position;
	
	//	spherically interpolate hop rotation
	glm::quat r = glm::slerp(m_hipFrames[0].rotation, m_hipFrames[1].rotation, s);

	//	update the hip bone
	m_hipBone = glm::translate(p) * glm::toMat4(r);

	#pragma endregion Leg Animation

	// add a transform so that we can see the axis
	Gizmos::addTransform(mat4(1));

	// quit if we press escape
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	{
		quit();
	}
	if (input->isKeyDown(aie::INPUT_KEY_P))
	{
		start = true;
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

void GoThroughPositionsInLoop(int numOfPositions, float timerLerp)
{
	// Iterator to move forward
	int interator = 0; //starts at zero, to move from to zero to zero + 1

	
}