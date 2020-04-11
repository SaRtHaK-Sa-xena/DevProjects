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

	//Rendering Geometry-----
	m_shader.loadShader(aie::eShaderStage::VERTEX, "../bin/shaders/normalmap.vert");
	m_shader.loadShader(aie::eShaderStage::FRAGMENT, "../bin/shaders/normalmap.frag");
	
	m_texturedShader.loadShader(aie::eShaderStage::VERTEX, "../bin/shaders/textured.vert");
	m_texturedShader.loadShader(aie::eShaderStage::FRAGMENT, "../bin/shaders/textured.frag");

	m_phongShader.loadShader(aie::eShaderStage::VERTEX, "../bin/shaders/phong.vert");
	m_phongShader.loadShader(aie::eShaderStage::FRAGMENT, "../bin/shaders/phong.frag");

	m_postShader.loadShader(aie::eShaderStage::VERTEX, "../bin/shaders/post.vert");
	m_postShader.loadShader(aie::eShaderStage::FRAGMENT, "../bin/shaders/post.frag");

	m_particleShader.loadShader(aie::eShaderStage::VERTEX, "../bin/shaders/particle.vert");
	m_particleShader.loadShader(aie::eShaderStage::FRAGMENT, "../bin/shaders/particle.frag");

	m_lightingShader.loadShader(aie::eShaderStage::VERTEX, "../bin/shaders/lighting.vert");
	m_lightingShader.loadShader(aie::eShaderStage::FRAGMENT, "../bin/shaders/lighting.frag");

	m_pointLightShader.loadShader(aie::eShaderStage::VERTEX, "../bin/shaders/pointLight.vert");
	m_pointLightShader.loadShader(aie::eShaderStage::FRAGMENT, "../bin/shaders/pointLight.frag");

	//	Normal Map Spear Shader
	if (m_shader.link() == false)
	{
		printf("Shader Error: %s\n", m_shader.getLastError());
		return false;
	}

	//	SpotLight Shader
	if (m_lightingShader.link() == false)
	{
		printf("Shader Error: %s\n", m_lightingShader.getLastError());
		return false;
	}

	//	PointLight Shader
	if (m_pointLightShader.link() == false)
	{
		printf("Shader ErrorL %s\n", m_pointLightShader.getLastError());
		return false;
	}

	
	if (m_texturedShader.link() == false)
	{
		printf("Shader Error: %s\n", m_texturedShader.getLastError());
		return false;
	}

	if (m_phongShader.link() == false)
	{
		printf("Shader Error: %s\n", m_phongShader.getLastError());
		return false;
	}

	if (m_postShader.link() == false)
	{
		printf("Shader Error: %s\n", m_postShader.getLastError());
		return false;
	}

	if (m_particleShader.link() == false)
	{
		printf("Shader Error: %s\n", m_particleShader.getLastError());
		return false;

	}

	// Create render target with single target and dimensions as the screen
	if (m_renderTarget.initialise(1, getWindowWidth(),
		getWindowHeight()) == false) {
		printf("Render Target Error!\n");
		return false;
	}

	#pragma region Drawing

		#pragma region Drawing Quad
		
		/*if (m_gridTexture.load("../bin/textures/numbered_grid.tga") == false) {
			printf("Failed to load texture!\n");
			return false;
		}*/

		// define 6 vertices for 2 triangles
		/*Mesh::Vertex vertices[6];
		vertices[0].position = { -0.5f, 0, 0.5f, 1 };
		vertices[1].position = { 0.5f, 0, 0.5f, 1 };
		vertices[2].position = { -0.10f, 0, -0.5f, 1 };
		vertices[3].position = { -0.5f, 0, -0.5f, 1 };
		vertices[4].position = { 0.5f, 0, 0.5f, 1 };
		vertices[5].position = { 0.5f, 0, -0.5f, 1 };
		m_quadMesh.initialise(6, vertices);*/

		//m_fullScreenQuad.initialiseFullScreenQuad();

		////make the quad 10 units wide
		//m_quadTransform = {
		//10,0,0,0,
		//0,10,0,0,
		//0,0,10,0,
		//0,0,0,1 };

		#pragma endregion Rendering Quad

		#pragma region Drawing Dragon
	
		if (m_dragonMesh.load("../bin/stanford/stanford/Dragon.obj") == false) {
			printf("Dragon Mesh Error!\n");
			return false;
		}

		m_dragonTransform = {
		0.5f,0,0,0,
		0,0.5f,0,0,
		0,0,0.5f,0,
		-2,0,-2,1
		};

		#pragma endregion Rendering Dragon

		#pragma region Drawing Bunny
		
		if (m_bunnyMesh.load("../bin/stanford/stanford/Bunny.obj") == false) {
			printf("Bunny Mesh Error!\n");
			return false;
		}
		
		m_bunnyTransform = {
		//scale
		0.5,0,0,0,
		0,0.5,0,0,
		0,0,0.5,0,
		
		//position
		2,0,2,1
		};

		#pragma endregion Rendering Bunny
	
		#pragma region Drawing Spear

		if (m_spearMesh.load("../bin/soulspear/soulspear/soulspear.obj",
			true, true) == false) {
			printf("Soulspear Mesh Error!\n");
			return false;
		}
		m_spearTransform = {
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		-2,0,2,1
		};

		#pragma endregion Rendering Spear

		#pragma region Drawing Particle
		
		m_emitter = new ParticleEmitter();
		m_emitter->initalise(1000, 500,
			0.1f, 1.0f,
			1, 5,
			1, 0.1f,
			glm::vec4(1, 0, 0, 1), glm::vec4(1, 1, 0, 1));

		m_particleTransform = {
			10,0,0,0,
			0,10,0,0,
			0,0,10,0,
			0,0,0,1 };

		#pragma endregion Emit Particles

	#pragma endregion Rendering

	//Rendering Geometry-----

	//==== Lighting ====
	//=== Modified ===
	m_light.diffuse = { 1, 1, 1 };
	m_light.specular = {1, 1, 1 };

	m_pointLight.diffuse = { 1,1,1 };
	m_pointLight.specular = { 1,1,1 };

	m_ambientLight = { 1.f, 1.f, 0.f };
	
	//=== Default ===
	/*m_light.diffuse = { 1, 1, 0 };
	m_light.specular = {1, 1, 0 };
	m_ambientLight = { 0.25f, 0.25f, 0.25f };*/

	//m_light.constant = 1.f;
	//m_light.quadratic = 1.f;
	//m_light.linear = 1.f;
	//m_light.position = { 0,0,0 };

	// Light Obj Position
	m_positions[0] = glm::vec3(0, 5, 0);
	m_rotations[0] = glm::quat(glm::vec3(0, 0, 0));

	// PointLight Obj Position
	m_positions[1] = glm::vec3(0, 10, 0);
	m_rotations[1] = glm::quat(glm::vec3(0, 0, 0));


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
	//
	////	animate leg
	//float s = glm::cos(getTime()) * 0.5f + 0.5f;

	////	linearly interpolate position
	//glm::vec3 p = (1.0f - s) * m_hipFrames[0].position + s * m_hipFrames[1].position;
	//
	////	spherically interpolate hop rotation
	//glm::quat r = glm::slerp(m_hipFrames[0].rotation, m_hipFrames[1].rotation, s);

	////	update the hip bone
	//m_hipBone = glm::translate(p) * glm::toMat4(r);

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

	//==================LIGHT========================
	// query time since application started
	//float time = getTime();
	
	// rotate light
	//m_light.direction = glm::normalize(vec3(glm::cos(time * 2),
		//glm::sin(time * 2), 0));

	//point direcitonal light straight down
	//m_light.direction = glm::vec3(0, -1, 0);

	//Gizmos::addTransform(m);
	
	
	//	Update emitter
	//m_emitter->update(deltaTime, myCamera->GetProjectionView());

	//	update camera
	myCamera->Update(deltaTime);

	//====Zoom in on angle
	//m_viewMatrix = glm::inverse(m_viewMatrix);

	// what happens here?

	//m_viewMatrix = m_viewMatrix + glm::translate(m_viewMatrix, glm::vec3(m_viewMatrix[2].x, m_viewMatrix[2].y, m_viewMatrix[2].z)*0.1f);

	//====Zoom out on angle
	/*m_viewMatrix = glm::inverse(m_viewMatrix);

	m_viewMatrix = m_viewMatrix - deltaTime * glm::translate(m_viewMatrix, glm::vec3(m_viewMatrix[3].x, m_viewMatrix[3].y, m_viewMatrix[3].z));*/
	
	

	if (switchMovement == true)
	{
		if (input->isKeyDown(aie::INPUT_KEY_Y))
		{
			m_positions[1].y += 0.1f;
		}
		if (input->isKeyDown(aie::INPUT_KEY_U))
		{
			m_positions[1].y -= 0.1f;
		}
		if (input->isKeyDown(aie::INPUT_KEY_J))
		{
			m_positions[1].x += 0.1f;
		}
		if (input->isKeyDown(aie::INPUT_KEY_L))
		{
			m_positions[1].x -= 0.1f;
		}
		if (input->isKeyDown(aie::INPUT_KEY_K))
		{
			m_positions[1].z -= 0.1f;
		}
		if (input->isKeyDown(aie::INPUT_KEY_I))
		{
			m_positions[1].z += 0.1f;
		}
	}
	else if(switchMovement == false)
	{
		if (input->isKeyDown(aie::INPUT_KEY_Y))
		{
			m_positions[0].y += 0.1f;
		}
		if (input->isKeyDown(aie::INPUT_KEY_U))
		{
			m_positions[0].y -= 0.1f;
		}
		if (input->isKeyDown(aie::INPUT_KEY_J))
		{
			m_positions[0].x += 0.1f;
		}
		if (input->isKeyDown(aie::INPUT_KEY_L))
		{
			m_positions[0].x -= 0.1f;
		}
		if (input->isKeyDown(aie::INPUT_KEY_K))
		{
			m_positions[0].z -= 0.1f;
		}
		if (input->isKeyDown(aie::INPUT_KEY_I))
		{
			m_positions[0].z += 0.1f;
		}
	}
	

	if (input->isKeyDown(aie::INPUT_KEY_0))
	{
		if (switchMovement)
		{
			switchMovement = false;
		}
		else if(switchMovement == false)
		{
			switchMovement = true;
		}
	}

	//========================SpotLight================================================
	p = m_positions[0];
	r = m_rotations[0];
	
	//	build a matrix
	glm::mat4 box_matrix = glm::translate(p) * glm::toMat4(r);

	//	draw a transform and box
	Gizmos::addTransform(glm::inverseTranspose(glm::mat3(box_matrix)));
	Gizmos::addAABBFilled(p, glm::vec3(.5f), glm::vec4(1, 0, 0, 1), &glm::mat4(glm::inverseTranspose(glm::mat3(box_matrix))));

	//	light position
	lightPos = m_positions[0];

	//	assign variables
	m_light.position = lightPos;
	m_light.direction = glm::vec3(box_matrix[0].z, box_matrix[1].z, box_matrix[2].z);
	//========================SpotLight================================================


	//========================PointLight===============================================
	pointLight_p = m_positions[1];
	pointLight_r = m_rotations[1];

	//	build a matrix for spotlight
	glm::mat4 pointLight_matrix = glm::translate(pointLight_p) * glm::toMat4(pointLight_r);

	Gizmos::addTransform(pointLight_matrix);//glm::inverseTranspose(glm::mat3(spotLight_matrix)));
	Gizmos::addAABBFilled(pointLight_p, glm::vec3(.5f), glm::vec4(0, 1, 0, 1), &pointLight_matrix);//&glm::mat4(glm::inverseTranspose(glm::mat3(spotLight_matrix))));

	pointLightPos = m_positions[1];

	// no direction, since it is a point light
	m_pointLight.position = pointLightPos;
	//========================PointLight===============================================

	//lightPos = glm::inverseTranspose(glm::mat3(box_matrix))[0];
}

void ComputerGraphicsApp::draw() {

	clearScreen();

	#pragma region RenderTarget

	////	bind out render target
	//m_renderTarget.bind();

	//// wipe the screen to the background colour
	//clearScreen();

	//// bind shader
	//m_phongShader.bind();

	//// allow light properties to render using camera position 
	//m_phongShader.bindUniform("cameraPosition", myCamera->GetPosition());

	//// bind light
	//m_phongShader.bindUniform("Id", m_light.diffuse);
	//m_phongShader.bindUniform("Ia", m_ambientLight);
	//m_phongShader.bindUniform("Is", m_light.specular);
	//m_phongShader.bindUniform("lightDirection", m_light.direction);

	//// bind transform							//To tranform being used
	//auto pvm = myCamera->GetProjectionView() * m_bunnyTransform;
	//m_phongShader.bindUniform("ProjectionViewModel", pvm);


	//// bind model matrix
	//m_phongShader.bindUniform("ModelMatrix", m_bunnyTransform);


	//// bind transforms for lighting
	//m_phongShader.bindUniform("NormalMatrix",
	//	glm::inverseTranspose(glm::mat3(m_bunnyTransform)));

	////	draw mesh 
	//m_bunnyMesh.draw();

	//// unbind target to return to backbuffer
	//m_renderTarget.unbind();

	////	clear the backbuffer
	//clearScreen();

	////	 bind texturing shader
	//m_texturedShader.bind();
	//pvm = myCamera->GetProjectionView() * m_quadTransform;
	//m_texturedShader.bindUniform("ProjectionViewModel", pvm);
	//m_texturedShader.bindUniform("diffuseTexture", 0);
	//m_renderTarget.getTarget(0).bind(0);

	//// draw quad, with the assigned mesh texture
	//m_quadMesh.draw();

	#pragma endregion Draw Model as Texture on Quad

	#pragma region RenderTarget

	////	bind out render target
	//m_renderTarget.bind();

	//// wipe the screen to the background colour
	//clearScreen();

	//// bind shader
	//m_phongShader.bind();

	//// allow light properties to render using camera position 
	//m_phongShader.bindUniform("cameraPosition", myCamera->GetPosition());

	//// bind light
	//m_phongShader.bindUniform("Id", m_light.diffuse);
	//m_phongShader.bindUniform("Ia", m_ambientLight);
	//m_phongShader.bindUniform("Is", m_light.specular);
	//m_phongShader.bindUniform("lightDirection", m_light.direction);

	//// bind transform							//To tranform being used
	//auto pvm = myCamera->GetProjectionView() * m_dragonTransform;
	//m_phongShader.bindUniform("ProjectionViewModel", pvm);


	//// bind model matrix
	//m_phongShader.bindUniform("ModelMatrix", m_dragonTransform);


	//// bind transforms for lighting
	//m_phongShader.bindUniform("NormalMatrix",
	//	glm::inverseTranspose(glm::mat3(m_dragonTransform)));

	////	draw mesh 
	//m_dragonMesh.draw();

	//// unbind target to return to backbuffer
	//m_renderTarget.unbind();

	////	clear the backbuffer
	//clearScreen();

	////	bind post shader and textures
	//m_postShader.bind();
	//m_postShader.bindUniform("colourTarget", 0);
	//m_renderTarget.getTarget(0).bind(0);
	//
	//// draw fullscreen quad
	//m_fullScreenQuad.draw();

	#pragma endregion Draw With Post-Processing

	#pragma region Particle System

	//// bind particle shader
	//m_particleShader.bind();

	//// bind particle transform
	//auto pvm = m_projectionMatrix * m_viewMatrix * m_particleTransform;

	//m_particleShader.bindUniform("ProjectionViewModel", pvm);
	//m_emitter->draw();

	#pragma endregion Draw Emitter Particles

	#pragma region Default

	//clearScreen();
	//
	//m_phongShader.bind();
	//
	//// allow light properties to render using camera position 
	//m_phongShader.bindUniform("cameraPosition", myCamera->GetPosition());
	//
	//// bind light
	//m_phongShader.bindUniform("Id", m_light.diffuse);
	//m_phongShader.bindUniform("Ia", m_ambientLight);
	//m_phongShader.bindUniform("Is", m_light.specular);
	//m_phongShader.bindUniform("lightDirection", m_light.direction);
	//
	//// bind transform							//To tranform being used
	//auto pvm = myCamera->GetProjectionView() * m_bunnyTransform;
	//m_phongShader.bindUniform("ProjectionViewModel", pvm);
	//
	//
	//// bind model matrix
	//m_phongShader.bindUniform("ModelMatrix", m_bunnyTransform);
	//
	//
	//// bind transforms for lighting
	//m_phongShader.bindUniform("NormalMatrix",
	//	glm::inverseTranspose(glm::mat3(m_bunnyTransform)));
	//
	////	draw mesh 
	//m_bunnyMesh.draw();

	#pragma endregion Draw def_Model and def_Light

	#pragma region Assignement

	//m_phongShader.bind();
	//
	//// allow light properties to render using camera position 
	//m_phongShader.bindUniform("cameraPosition", myCamera->GetPosition());
	//m_phongShader.bindUniform("Id", m_light.diffuse);
	//m_phongShader.bindUniform("Ia", m_ambientLight);
	//m_phongShader.bindUniform("Is", m_light.specular);
	//m_phongShader.bindUniform("lightDirection", m_light.direction);
	//
	//auto pvm = myCamera->GetProjectionView() * m_bunnyTransform;
	//m_phongShader.bindUniform("ProjectionViewModel", pvm);
	//
	//// bind model matrix
	//m_phongShader.bindUniform("ModelMatrix", m_bunnyTransform);
	//// bind transforms for lighting
	//m_phongShader.bindUniform("NormalMatrix",
	//	glm::inverseTranspose(glm::mat3(m_bunnyTransform)));
	//
	////	draw mesh 
	//m_bunnyMesh.draw();
	//
	//m_shader.bind();
	//
	//// allow light properties to render using camera position 
	//m_shader.bindUniform("cameraPosition", myCamera->GetPosition());
	//m_shader.bindUniform("Id", m_light.diffuse);
	//m_shader.bindUniform("Ia", m_ambientLight);
	//m_shader.bindUniform("Is", m_light.specular);
	//m_shader.bindUniform("lightDirection", m_light.direction);
	//
	//pvm = myCamera->GetProjectionView() * m_spearTransform;
	//m_shader.bindUniform("ProjectionViewModel", pvm);
	//
	//// bind model matrix
	//m_shader.bindUniform("ModelMatrix", m_spearTransform);
	//// bind transforms for lighting
	//m_shader.bindUniform("NormalMatrix",
	//	glm::inverseTranspose(glm::mat3(m_spearTransform)));
	//
	//m_spearMesh.draw();
	//
	////Gizmos::draw(m_projectionMatrix * m_viewMatrix);
	//Gizmos::draw(myCamera->GetProjectionView());
	//
	//// draw 2D gizmos using an orthogonal projection matrix
	//Gizmos::draw2D((float)getWindowWidth(), (float)getWindowHeight());
	
	#pragma endregion 1 Stan, 1 mod, 1 light

	m_lightingShader.bind();
	
	// allow light properties to render using camera position 
	m_lightingShader.bindUniform("cameraPosition", myCamera->GetPosition());
	m_lightingShader.bindUniform("Id", m_light.diffuse);
	m_lightingShader.bindUniform("Ia", m_ambientLight);
	m_lightingShader.bindUniform("Is", m_light.specular);
	m_lightingShader.bindUniform("lightPosition", m_light.position);
	m_lightingShader.bindUniform("constant", 1.0f);
	m_lightingShader.bindUniform("linear", 0.09f);
	m_lightingShader.bindUniform("quadratic", 0.032f);
	
	//	if Spotlight->
	m_lightingShader.bindUniform("lightDirection", m_light.direction);
	m_lightingShader.bindUniform("cutOff", glm::cos(glm::radians(12.5f)));
	m_lightingShader.bindUniform("outerCutOff", glm::cos(glm::radians(17.5f)));
	
	auto pvm = myCamera->GetProjectionView() * m_bunnyTransform;
	m_lightingShader.bindUniform("ProjectionViewModel", pvm);
	
	// bind model matrix
	m_lightingShader.bindUniform("ModelMatrix", m_bunnyTransform);
	// bind transforms for lighting
	m_lightingShader.bindUniform("NormalMatrix",
		glm::inverseTranspose(glm::mat3(m_bunnyTransform)));
	
	//	draw mesh 
	m_bunnyMesh.draw();
	
	//start new shader for point light
	m_pointLightShader.bind();

	m_pointLightShader.bindUniform("cameraPosition", myCamera->GetPosition());
	m_pointLightShader.bindUniform("Id", m_pointLight.diffuse);
	m_pointLightShader.bindUniform("Ia", m_ambientLight);
	m_pointLightShader.bindUniform("Is", m_pointLight.specular);
	m_pointLightShader.bindUniform("lightPosition", m_pointLight.position);
	m_pointLightShader.bindUniform("constant", 1.0f);
	m_pointLightShader.bindUniform("linear", 0.09f);
	m_pointLightShader.bindUniform("quadratic", 0.032f);

	pvm = myCamera->GetProjectionView() * m_dragonTransform;
	m_lightingShader.bindUniform("ProjectionViewModel", pvm);

	// bind model matrix
	m_lightingShader.bindUniform("ModelMatrix", m_dragonTransform);
	// bind transforms for lighting
	m_lightingShader.bindUniform("NormalMatrix",
		glm::inverseTranspose(glm::mat3(m_dragonTransform)));

	//	draw mesh 
	m_dragonMesh.draw();

	m_shader.bind();
	
	// allow light properties to render using camera position 
	m_shader.bindUniform("cameraPosition", myCamera->GetPosition());
	m_shader.bindUniform("Id", m_light.diffuse);
	m_shader.bindUniform("Ia", m_ambientLight);
	m_shader.bindUniform("Is", m_light.specular);
	m_shader.bindUniform("lightPosition", m_light.position);
	m_shader.bindUniform("constant", 1.0f);
	m_shader.bindUniform("linear", 0.09f);
	m_shader.bindUniform("quadratic", 0.032f);

	
	pvm = myCamera->GetProjectionView() * m_spearTransform;
	m_shader.bindUniform("ProjectionViewModel", pvm);
	
	// bind model matrix
	m_shader.bindUniform("ModelMatrix", m_spearTransform);
	// bind transforms for lighting
	m_shader.bindUniform("NormalMatrix",
		glm::inverseTranspose(glm::mat3(m_spearTransform)));
	
	m_spearMesh.draw();
	
	//Gizmos::draw(m_projectionMatrix * m_viewMatrix);
	Gizmos::draw(myCamera->GetProjectionView());
	
	// draw 2D gizmos using an orthogonal projection matrix
	Gizmos::draw2D((float)getWindowWidth(), (float)getWindowHeight());
}

