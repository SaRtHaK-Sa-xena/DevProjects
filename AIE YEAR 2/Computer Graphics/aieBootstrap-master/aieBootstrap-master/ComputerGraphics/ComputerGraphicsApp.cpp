#define GLM_ENABLE_EXPERIMENTAL
#include "ComputerGraphicsApp.h"
#include <iostream>
#include "Gizmos.h"
#include "Input.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtx/transform.hpp>
#include "Font.h"


using glm::vec3;
using glm::vec4;
using glm::mat4;
using aie::Gizmos;

ComputerGraphicsApp::ComputerGraphicsApp() {

}

ComputerGraphicsApp::~ComputerGraphicsApp() {

}

bool ComputerGraphicsApp::startup() {
	
	// 2D Renderer
	m_2dRenderer = new aie::Renderer2D();

	//	Font to be used
	m_font = new aie::Font("./font/consolas.ttf", 32);


	setBackgroundColour(0.25f, 0.25f, 0.25f);

	// initialise gizmo primitive counts
	Gizmos::create(10000, 10000, 10000, 10000);
	
	// Camera Initialize
	myCamera->Lookat(glm::vec3(10));
	myCamera->SetProjection(glm::pi<float>() * 0.25f, 16.0f / 9.0f, 0.1f, 1000.0f);

	// create simple camera transforms
	m_viewMatrix = glm::lookAt(vec3(10), vec3(0), vec3(0, 1, 0));
	m_projectionMatrix = glm::perspective(glm::pi<float>() * 0.25f, 16.0f / 9.0f, 0.1f, 1000.0f);

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

	m_multipleLightsShader.loadShader(aie::eShaderStage::VERTEX, "../bin/shaders/multipleLights.vert");
	m_multipleLightsShader.loadShader(aie::eShaderStage::FRAGMENT, "../bin/shaders/multipleLights.frag");

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

	//	PointLight Shader
	if (m_multipleLightsShader.link() == false)
	{
		printf("Shader ErrorL %s\n", m_multipleLightsShader.getLastError());
		return false;
	}

	//	more shaders for future
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
		
		// full screen quad initialized for post processing	
		m_fullScreenQuad.initialiseFullScreenQuad();

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
		5,0,5,1
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
		-2,0,-2,1
		};

		#pragma endregion Rendering Spear
		
		#pragma region Drawing Sword

		if (m_swordMesh.load("../bin/Models/ArthurSword/new_sword/new_sword.obj",
			true, true) == false) {
			printf("Sword Mesh Error!\n");
			return false;
		}
		m_swordTransform = {
		0.001,0,0,0,
		0,0.001,0,0,
		0,0,0.001,0,
		-5,0,5,1
		};

		#pragma endregion Rendering Sword

	#pragma endregion Rendering

	//Rendering Geometry-----

	//==== Lighting ====
	//	Assign sword point Light Member Variables 
	m_swordPointLight.Ia = { 0,1,0 }; // green
	m_swordPointLight.Id = { 0,1,0 }; // green
	m_swordPointLight.Is = { 0,1,0 }; // green
	m_swordPointLight.constant = 1.f;
	m_swordPointLight.linear = 0.09f;
	m_swordPointLight.quadratic = 0.032f;
	
	//	Assign bunny point Light Member Variables
	m_bunnyLight.Ia = { 0,0.7, 0.7 }; // light blue
	m_bunnyLight.Id = { 0,0.7, 0.7 }; // light blue
	m_bunnyLight.Is = { 0,0.7, 0.7 }; // light blue
	m_bunnyLight.constant = 1.f;
	m_bunnyLight.linear = 0.09f;
	m_bunnyLight.quadratic = 0.032f;

	//	Assign spear point Light Member Variables
	pointLight.Ia = { 1.f, 0.f, 0.f };
	pointLight.Id = { 1,0,0 };	// red
	pointLight.Is = { 1,0,0 };	// red
	pointLight.constant = 1.f;
	pointLight.linear = 0.09f;
	pointLight.quadratic = 0.032f;

	//	Assign spot Light Member Variables
	spotLight.Ia = { 1,0,0 };
	spotLight.Id = { 1,0,0 };	// red
	spotLight.Is = { 1,0,0 };	// red
	spotLight.cutOff = glm::cos(glm::radians(12.5f));
	spotLight.outerCutOff = glm::cos(glm::radians(17.5f));
	spotLight.constant = 1.f;
	spotLight.linear = 0.09f;
	spotLight.quadratic = 0.032f;

	//	Assign directional Light Member Variables
	dirLight.Ia = { 1.f, 1.f, 1.f };
	dirLight.Id = { 1,1,1 }; //	white
	dirLight.Is = { 1,1,1 }; //	white
	
	// Static Point Light Obj Position
	m_positions[0] = glm::vec3(-7, 1, 5);
	m_rotations[0] = glm::quat(glm::vec3(0, 0, 0));

	// PointLight Obj Position
	m_positions[1] = glm::vec3(5, 1, 9);
	m_rotations[1] = glm::quat(glm::vec3(0, 0, 0));

	//	pointLight Positions
	pointLight_positions[0] = glm::vec3(-7, 2, -2);
	pointLight_positions[1] = glm::vec3(-5, 2, -4.3);
	pointLight_positions[2] = glm::vec3(-2, 2, -4.9);
	pointLight_positions[3] = glm::vec3(0.9, 2, -4.2);
	pointLight_positions[4] = glm::vec3(3, 2, -3.1);
	pointLight_positions[5] = glm::vec3(2.9, 2, -1);
	pointLight_positions[6] = glm::vec3(0, 2, 0.3);
	pointLight_positions[7] = glm::vec3(-3.5, 2, 0.7);
	pointLight_positions[8] = glm::vec3(-6, 2, 0.3);

	//	pointLight Rotations
	pointLight_rotations[0] = glm::quat(glm::vec3(0, 0, 0));
	pointLight_rotations[1] = glm::quat(glm::vec3(0, 0, 0));
	pointLight_rotations[2] = glm::quat(glm::vec3(0, 0, 0));
	pointLight_rotations[3] = glm::quat(glm::vec3(0, 0, 0));
	pointLight_rotations[4] = glm::quat(glm::vec3(0, 0, 0));
	pointLight_rotations[5] = glm::quat(glm::vec3(0, 0, 0));
	pointLight_rotations[6] = glm::quat(glm::vec3(0, 0, 0));
	pointLight_rotations[7] = glm::quat(glm::vec3(0, 0, 0));
	pointLight_rotations[8] = glm::quat(glm::vec3(0, 0, 0));


	//	spotLight Positions
	spotLight_positions[0] = glm::vec3(0.5, 2, 5.3);
	spotLight_positions[1] = glm::vec3(1, 2, 3);
	spotLight_positions[2] = glm::vec3(4, 2, 1.8);
	spotLight_positions[3] = glm::vec3(6.6, 2, 2);
	spotLight_positions[4] = glm::vec3(9.5, 2, 4.2);
	spotLight_positions[5] = glm::vec3(9, 2, 7);
	spotLight_positions[6] = glm::vec3(6.2, 2, 8.8);
	spotLight_positions[7] = glm::vec3(3.1, 2, 8.1);
	spotLight_positions[8] = glm::vec3(1, 2, 7.1);


	//	spotLight Rotations
	spotLight_rotations[0] = glm::quat(glm::vec3(0, 0, 0));
	spotLight_rotations[1] = glm::quat(glm::vec3(0, 0, 0));
	spotLight_rotations[2] = glm::quat(glm::vec3(0, 0, 0));
	spotLight_rotations[3] = glm::quat(glm::vec3(0, 0, 0));
	spotLight_rotations[4] = glm::quat(glm::vec3(0, 0, 0));
	spotLight_rotations[5] = glm::quat(glm::vec3(0, 0, 0));
	spotLight_rotations[6] = glm::quat(glm::vec3(0, 0, 0));
	spotLight_rotations[7] = glm::quat(glm::vec3(0, 0, 0));
	spotLight_rotations[8] = glm::quat(glm::vec3(0, 0, 0));


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

	// increase time
	pointLightTime += deltaTime;
	spotLightTime += deltaTime;

	//	if it reaches the destination
	if (pointLightTime >= 1.f)
	{
		pointLightTime = 0.f;
		increment++;
		
		if (increment == 0)
		{
			resetToStartPosition = false;
		}

		// if at final destination
		if (increment >= 8)
		{
			increment = -1;
			resetToStartPosition = true;
		}
	}

	if (spotLightTime >= 1.f)
	{
		spotLightTime = 0.f;
		increment_spotLight++;

		if (increment_spotLight == 0)
		{
			resetToStartPosition_spotLight = false;
		}

		// if at final destination
		if (increment_spotLight >= 8)
		{
			increment_spotLight = -1;
			resetToStartPosition_spotLight = true;
		}
	}

	//	if it needs to reset
	if (resetToStartPosition)
	{
		//							      from last position		    to beginning position
		pointLightPosition = (1.0f - pointLightTime) * pointLight_positions[8] + pointLightTime * pointLight_positions[0];
		pointLightRotation = glm::slerp(pointLight_rotations[8], pointLight_rotations[0], pointLightTime);
	}
	else
	{
		pointLightPosition = (1.0f - pointLightTime) * pointLight_positions[increment] + pointLightTime * pointLight_positions[increment + 1];
		
		//	quaternion slerp //==Box's rotation from one point to another
		pointLightRotation = glm::slerp(pointLight_rotations[increment], pointLight_rotations[increment + 1], pointLightTime);
	}
	
	if (resetToStartPosition_spotLight)
	{
		spotLightPosition = (1.0f - spotLightTime) * spotLight_positions[8] + spotLightTime * spotLight_positions[0];
		
		//	quaternion slerp //==Box's rotation from one point to another
		spotLightRotation = glm::slerp(spotLight_rotations[8], spotLight_rotations[0], spotLightTime);
	}
	else
	{
		spotLightPosition = (1.0f - spotLightTime) * spotLight_positions[increment_spotLight] + spotLightTime * spotLight_positions[increment_spotLight + 1];

		//	quaternion slerp //==Box's rotation from one point to another
		spotLightRotation = glm::slerp(spotLight_rotations[increment_spotLight], spotLight_rotations[increment_spotLight + 1], spotLightTime);
	}

	// add a transform so that we can see the axis
	Gizmos::addTransform(mat4(1));

	// quit if we press escape
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	{
		quit();
	}
	if (input->isKeyDown(aie::INPUT_KEY_4)) {
		distortionEffect = true;
	}
	if (input->isKeyDown(aie::INPUT_KEY_5)) {
		distortionEffect = false;
	}

	//	update camera
	myCamera->Update(deltaTime);

	//========================SpotLight================================================
	//	build a matrix
	glm::mat4 spotLight_matrix = glm::translate(spotLightPosition) * glm::toMat4(spotLightRotation);

	//	draw a transform and box
	Gizmos::addTransform(glm::inverseTranspose(glm::mat3(spotLight_matrix)));
	Gizmos::addAABBFilled(spotLightPosition, glm::vec3(.5f), glm::vec4(1, 0, 0, 1), &glm::mat4(glm::inverseTranspose(glm::mat3(spotLight_matrix))));

	spotLight.position = spotLightPosition;
	spotLight.direction = glm::vec3(spotLight_matrix[0].z, spotLight_matrix[1].z, spotLight_matrix[2].z);
	//========================SpotLight================================================


	//======================= PointLight ==============================================
	//	build a matrix for pointLight
	glm::mat4 pointLight_matrix = glm::translate(pointLightPosition) * glm::toMat4(pointLightRotation);

	Gizmos::addTransform(pointLight_matrix);
	Gizmos::addAABBFilled(pointLightPosition, glm::vec3(.5f), glm::vec4(1, 0, 0, 1), &glm::inverseTranspose(pointLight_matrix));

	// New addition
	// point light position
	pointLight.position = pointLightPosition;

	// directional light direction
	dirLight.direction = glm::vec3(1,-1,0);
	//======================= PointLight ==============================================

	//======================= PointLight On Sword =====================================
	glm::mat4 swordPointLight_matrix = glm::translate(m_positions[0]) * glm::toMat4(m_rotations[0]);

	Gizmos::addTransform(swordPointLight_matrix);
	Gizmos::addAABBFilled(m_positions[0], glm::vec3(.5f), glm::vec4(0, 1, 0, 1), &glm::inverseTranspose(swordPointLight_matrix));

	m_swordPointLight.position = m_positions[0];
	//======================= PointLight On Sword =====================================

	// ===================== Point Light On Bunny =====================================
	glm::mat4 bunnyPointLight_matrix = glm::translate(m_positions[1]) * glm::toMat4(m_rotations[1]);

	Gizmos::addTransform(bunnyPointLight_matrix);
	Gizmos::addAABBFilled(m_positions[1], glm::vec3(.5f), glm::vec4(0, .7, .7, 1), &glm::inverseTranspose(bunnyPointLight_matrix));

	m_bunnyLight.position = m_positions[1];
	// ===================== Point Light On Bunny =====================================
}

void ComputerGraphicsApp::draw() {

	clearScreen();
	
	//	if distortion effect active
	if (distortionEffect)
	{
		//	bind out render target
		m_renderTarget.bind();

		//	clear screen
		clearScreen();
	}

	m_multipleLightsShader.bind();

	// start new shader for point light
	m_multipleLightsShader.bindUniform("cameraPosition", myCamera->GetPosition());

	// bind light properties for directional
	bindProperties_DIRLIGHT();

	m_multipleLightsShader.bindUniform("pointLight.Id", m_bunnyLight.Id);
	m_multipleLightsShader.bindUniform("pointLight.Ia", m_bunnyLight.Ia);
	m_multipleLightsShader.bindUniform("pointLight.Is", m_bunnyLight.Is);
	m_multipleLightsShader.bindUniform("pointLight.position", m_bunnyLight.position);
	m_multipleLightsShader.bindUniform("pointLight.constant", m_bunnyLight.constant);
	m_multipleLightsShader.bindUniform("pointLight.linear", m_bunnyLight.linear);
	m_multipleLightsShader.bindUniform("pointLight.quadratic", m_bunnyLight.quadratic);
	
	// bind light properties for spot light
	bindProperties_SPOTLIGHT();
	
	//== bind ProjectionViewModel, ModelMatrix, Transform and Draw Bunny ==
	auto pvm = myCamera->GetProjectionView() * m_bunnyTransform;
	m_multipleLightsShader.bindUniform("ProjectionViewModel", pvm);
	// bind model matrix
	m_multipleLightsShader.bindUniform("ModelMatrix", m_bunnyTransform);
	// bind transforms for lighting
	m_multipleLightsShader.bindUniform("NormalMatrix",
		glm::inverseTranspose(glm::mat3(m_bunnyTransform)));
	//	draw mesh 
	m_bunnyMesh.draw();

	//	assign textured OBJ shader
	m_shader.bind();

	//	assign properties in shader code
	m_shader.bindUniform("cameraPosition", myCamera->GetPosition());
	m_shader.bindUniform("Id", pointLight.Id);
	m_shader.bindUniform("Ia", pointLight.Ia);
	m_shader.bindUniform("Is", pointLight.Is);
	m_shader.bindUniform("lightPosition", pointLight.position);
	m_shader.bindUniform("constant", pointLight.constant);
	m_shader.bindUniform("linear", pointLight.linear);
	m_shader.bindUniform("quadratic", pointLight.quadratic);

	//== bind ProjectionViewModel, ModelMatrix, Transform and Draw Spear ==
	pvm = myCamera->GetProjectionView() * m_spearTransform;
	m_shader.bindUniform("ProjectionViewModel", pvm);
	// bind model matrix
	m_shader.bindUniform("ModelMatrix", m_spearTransform);
	// bind transforms for lighting
	m_shader.bindUniform("NormalMatrix",
		glm::inverseTranspose(glm::mat3(m_spearTransform)));
	//	draw spear OBJ
	m_spearMesh.draw();


	m_shader.bind();

	//	assign properties in shader code
	m_shader.bindUniform("cameraPosition", myCamera->GetPosition());
	m_shader.bindUniform("Id", m_swordPointLight.Id);
	m_shader.bindUniform("Ia", m_swordPointLight.Ia);
	m_shader.bindUniform("Is", m_swordPointLight.Is);
	m_shader.bindUniform("lightPosition", m_swordPointLight.position);
	m_shader.bindUniform("constant", m_swordPointLight.constant);
	m_shader.bindUniform("linear", m_swordPointLight.linear);
	m_shader.bindUniform("quadratic", m_swordPointLight.quadratic);

	//== bind ProjectionViewModel, ModelMatrix, Transform and Draw Sword ==
	pvm = myCamera->GetProjectionView() * m_swordTransform;
	m_shader.bindUniform("ProjectionViewModel", pvm);
	// bind model matrix
	m_shader.bindUniform("ModelMatrix", m_swordTransform);
	// bind transforms for lighting
	m_shader.bindUniform("NormalMatrix",
		glm::inverseTranspose(glm::mat3(m_swordTransform)));
	//	draw spear OBJ
	m_swordMesh.draw();
	//=====================================================================

	//	if distortion effect active
	if (distortionEffect)
	{
		// unbind target to return to backbuffer
		m_renderTarget.unbind();

		//	clear the backbuffer
		clearScreen();

		//	bind post shader and textures
		m_postShader.bind();
		m_postShader.bindUniform("colourTarget", 0);
		m_renderTarget.getTarget(0).bind(0);

		// draw fullscreen quad
		m_fullScreenQuad.draw();
	}

	Gizmos::draw(myCamera->GetProjectionView());
	
	// draw 2D gizmos using an orthogonal projection matrix
	Gizmos::draw2D((float)getWindowWidth(), (float)getWindowHeight());
}

//	binds properties of light for the directional light
void ComputerGraphicsApp::bindProperties_DIRLIGHT()
{
	m_multipleLightsShader.bindUniform("dirLight.Id", dirLight.Id);
	m_multipleLightsShader.bindUniform("dirLight.Ia", dirLight.Ia);
	m_multipleLightsShader.bindUniform("dirLight.Is", dirLight.Is);
	m_multipleLightsShader.bindUniform("dirLight.direction", dirLight.direction);
}

//	binds properties of light for the point light
void ComputerGraphicsApp::bindProperties_POINTLIGHT()
{
	m_multipleLightsShader.bindUniform("pointLight.Id", pointLight.Id);
	m_multipleLightsShader.bindUniform("pointLight.Ia", pointLight.Ia);
	m_multipleLightsShader.bindUniform("pointLight.Is", pointLight.Is);
	m_multipleLightsShader.bindUniform("pointLight.position", pointLight.position);
	m_multipleLightsShader.bindUniform("pointLight.constant", pointLight.constant);
	m_multipleLightsShader.bindUniform("pointLight.linear", pointLight.linear);
	m_multipleLightsShader.bindUniform("pointLight.quadratic", pointLight.quadratic);
}

//	binds properties of light for the spot light
void ComputerGraphicsApp::bindProperties_SPOTLIGHT()
{
	m_multipleLightsShader.bindUniform("spotLight.Id", spotLight.Id);
	m_multipleLightsShader.bindUniform("spotLight.Ia", spotLight.Ia);
	m_multipleLightsShader.bindUniform("spotLight.Is", spotLight.Is);
	m_multipleLightsShader.bindUniform("spotLight.position", spotLight.position);
	m_multipleLightsShader.bindUniform("spotLight.direction", spotLight.direction);
	m_multipleLightsShader.bindUniform("spotLight.cutOff", spotLight.cutOff);
	m_multipleLightsShader.bindUniform("spotLight.outerCutOff", spotLight.outerCutOff);
	m_multipleLightsShader.bindUniform("spotLight.constant", spotLight.constant);
	m_multipleLightsShader.bindUniform("spotLight.linear", spotLight.linear);
	m_multipleLightsShader.bindUniform("spotLight.quadratic", spotLight.quadratic);
}