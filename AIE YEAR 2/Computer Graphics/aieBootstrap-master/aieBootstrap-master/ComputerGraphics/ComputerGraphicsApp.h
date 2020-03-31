#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include "Application.h"
#include "Camera.h"
#include "Shader.h"
#include "Mesh.h"
#include "OBJMesh.h"
#include "RenderTarget.h"
#include "ParticleEmitter.h"

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
	float s=0;

	//Camera
	Camera *myCamera = new Camera();

	// camera transforms
	glm::mat4	m_viewMatrix;
	glm::mat4	m_projectionMatrix;

	glm::vec3	m_positions[3];
	glm::quat	m_rotations[3];

	//Renderering
	aie::Texture m_gridTexture;
	
	//	simple default shader
	aie::ShaderProgram	m_shader;
	
	//	textured 
	aie::ShaderProgram	m_texturedShader;

	//	lighting 
	aie::ShaderProgram	m_phongShader;

	//	postProcessing (using RenderTarget)
	aie::ShaderProgram	m_postShader;

	//	default quad
	Mesh				m_quadMesh;

	//	fullscreen quad
	Mesh				m_fullScreenQuad;

	//	Default Quad Transform
	glm::mat4			m_quadTransform;

	//	Obj Meshes
	aie::OBJMesh		m_bunnyMesh;
	glm::mat4			m_bunnyTransform;

	aie::OBJMesh		m_dragonMesh;
	glm::mat4			m_dragonTransform;

	aie::OBJMesh		m_spearMesh;
	glm::mat4			m_spearTransform;

	
	//	To render target
	aie::RenderTarget m_renderTarget;

	//	Particle Emitter

	ParticleEmitter		*m_emitter;

	// Light Variable
	struct Light 
	{
		glm::vec3 direction;
		glm::vec3 diffuse;
		glm::vec3 specular;
	};

	//Initialize light
	Light m_light;
	glm::vec3 m_ambientLight;



	//	move positions condition check
	bool decrementDown = false;

	//	increment value
	int scalar = 1;

	//	Check if it is going forward or backwards
	bool forward = true;

	bool start = false;

	struct KeyFrame {
		glm::vec3 position;
		glm::quat rotation;
	};

	KeyFrame m_hipFrames[2];
	KeyFrame m_kneeFrames[2];
	KeyFrame m_ankleFrames[2];

	glm::mat4 m_hipBone;
	glm::mat4 m_kneeBone;
	glm::mat4 m_ankleBone;
};