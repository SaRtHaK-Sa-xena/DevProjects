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
		
		#pragma region Default 

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

		////make the quad 10 units wide
		//m_quadTransform = {
		//10,0,0,0,
		//0,10,0,0,
		//0,0,10,0,
		//0,0,0,1 };

		#pragma endregion Default Ways Of Creating Quad 
		
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

		#pragma region Drawing Particle
		
		/*m_emitter = new ParticleEmitter();
		m_emitter->initalise(1000, 500,
			0.1f, 1.0f,
			1, 5,
			1, 0.1f,
			glm::vec4(1, 0, 0, 1), glm::vec4(1, 1, 0, 1));

		m_particleTransform = {
			10,0,0,0,
			0,10,0,0,
			0,0,10,0,
			0,0,0,1 };*/

		#pragma endregion Emit Particles

	#pragma endregion Rendering

	//Rendering Geometry-----

	//==== Lighting ====
	//red spot light
	m_light.diffuse = { 1, 0, 0 };
	m_light.specular = {1, 0, 0 };
	
	//green point light
	m_pointLight.diffuse = { 0,1,0 };
	m_pointLight.specular = { 0,1,0 };

	//white point light
	m_swordPointLight.diffuse = { 1,1,1 };
	m_swordPointLight.specular = { 1,1,1 };

	m_ambientLight = { 1.f, 1.f, 1.f };
	
	// Static Point Light Obj Position
	m_positions[0] = glm::vec3(-7, 1, 5);
	m_rotations[0] = glm::quat(glm::vec3(0, 0, 0));

	// PointLight Obj Position
	m_positions[1] = glm::vec3(0, 10, 0);
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
	p = m_positions[0];
	r = m_rotations[0];
	
	//	build a matrix
	glm::mat4 spotLight_matrix = glm::translate(spotLightPosition) * glm::toMat4(spotLightRotation);

	//	draw a transform and box
	Gizmos::addTransform(glm::inverseTranspose(glm::mat3(spotLight_matrix)));
	Gizmos::addAABBFilled(spotLightPosition, glm::vec3(.5f), glm::vec4(1, 0, 0, 1), &glm::mat4(glm::inverseTranspose(glm::mat3(spotLight_matrix))));

	//	assign variables
	m_light.position = spotLightPosition;
	m_light.direction = glm::vec3(spotLight_matrix[0].z, spotLight_matrix[1].z, spotLight_matrix[2].z);
	//========================SpotLight================================================


	//========================PointLight===============================================
	pointLight_p = m_positions[1];
	pointLight_r = m_rotations[1];

	//	build a matrix for pointLight
	glm::mat4 pointLight_matrix = glm::translate(pointLightPosition) * glm::toMat4(pointLightRotation);

	Gizmos::addTransform(pointLight_matrix);
	Gizmos::addAABBFilled(pointLightPosition, glm::vec3(.5f), glm::vec4(0, 1, 0, 1), &glm::inverseTranspose(pointLight_matrix));

	// no direction, since it is a point light
	m_pointLight.position = pointLightPosition;
	//========================PointLight===============================================

	//========================PointLight NUM 2===============================================
	glm::mat4 swordPointLight_matrix = glm::translate(m_positions[0]) * glm::toMat4(m_rotations[0]);

	Gizmos::addTransform(swordPointLight_matrix);
	Gizmos::addAABBFilled(m_positions[0], glm::vec3(.5f), glm::vec4(1, 1, 1, 1), &glm::inverseTranspose(swordPointLight_matrix));

	m_swordPointLight.position = m_positions[0];
}

void ComputerGraphicsApp::draw() {

	clearScreen();

	m_2dRenderer->begin();

	m_2dRenderer->drawText(m_font, "Press 4 to Distort Screen!", 0, 0);
	m_2dRenderer->drawText(m_font, "Press 5 to Revert!", 0, 0);

	m_2dRenderer->end();

	if (distortionEffect)
	{
		//	bind out render target
		m_renderTarget.bind();

		//	clear screen
		clearScreen();
	}

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
	//m_dragonMesh.draw();

	m_shader.bind();
	
	m_shader.bindUniform("cameraPosition", myCamera->GetPosition());
	m_shader.bindUniform("Id", m_swordPointLight.diffuse);
	m_shader.bindUniform("Ia", m_ambientLight);
	m_shader.bindUniform("Is", m_swordPointLight.specular);
	m_shader.bindUniform("lightPosition", m_swordPointLight.position);
	m_shader.bindUniform("constant", 1.0f);
	m_shader.bindUniform("linear", 0.07f);
	m_shader.bindUniform("quadratic", 0.017f);

	pvm = myCamera->GetProjectionView() * m_swordTransform;
	m_shader.bindUniform("ProjectionViewModel", pvm);
	
	// bind model matrix
	m_shader.bindUniform("ModelMatrix", m_swordTransform);
	// bind transforms for lighting
	m_shader.bindUniform("NormalMatrix",
		glm::inverseTranspose(glm::mat3(m_swordTransform)));

	m_swordMesh.draw();
	
	m_shader.bind();

	// allow light properties to render using camera position 
	m_shader.bindUniform("cameraPosition", myCamera->GetPosition());
	m_shader.bindUniform("Id", m_pointLight.diffuse);
	m_shader.bindUniform("Ia", m_ambientLight);
	m_shader.bindUniform("Is", m_pointLight.specular);
	m_shader.bindUniform("lightPosition", m_pointLight.position);
	m_shader.bindUniform("constant", 1.0f);
	m_shader.bindUniform("linear", 0.07f);
	m_shader.bindUniform("quadratic", 0.017f);

	pvm = myCamera->GetProjectionView() * m_spearTransform;
	m_shader.bindUniform("ProjectionViewModel", pvm);

	// bind model matrix
	m_shader.bindUniform("ModelMatrix", m_spearTransform);
	// bind transforms for lighting
	m_shader.bindUniform("NormalMatrix",
		glm::inverseTranspose(glm::mat3(m_spearTransform)));

	m_spearMesh.draw();

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

	//Gizmos::draw(m_projectionMatrix * m_viewMatrix);
	Gizmos::draw(myCamera->GetProjectionView());
	
	// draw 2D gizmos using an orthogonal projection matrix
	Gizmos::draw2D((float)getWindowWidth(), (float)getWindowHeight());

	


}


