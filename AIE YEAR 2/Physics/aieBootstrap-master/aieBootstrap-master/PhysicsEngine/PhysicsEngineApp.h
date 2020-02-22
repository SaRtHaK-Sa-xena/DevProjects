#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "PhysicsClass.h"
#include "SphereClass.h"
#include "AABBClass.h"

class PhysicsEngineApp : public aie::Application {
public:

	PhysicsEngineApp();
	virtual ~PhysicsEngineApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	void setupContinuousDemo(glm::vec2 startPos, float inclination, float speed, float gravity);

	//	player turn
	void startPhase();
	
	//	game turn
	void gamePhase();

	void selectPhase();

	PhysicsScene* m_physicsScene;

	SphereClass* rocket_Ship;
	
	// Being Used
	SphereClass* sphere;
	
	AABBClass* box1;
	AABBClass* box;
	SphereClass* striker;

	SphereClass* mousePointer = new SphereClass(glm::vec2(0, 0), 0, 0, 1, 2, glm::vec4(1, 0, 1, 1));

	glm::vec2 mouseCurrentPosition;

	// checks if player can shoot
	bool playerTurnActivated;

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	//objects in scene
	std::vector<SphereClass*> CoinsInScene;

	//Score Tracker for players
	int ScorePlayer1;
	int ScorePlayer2;

};

void setFoulPieces(std::vector<SphereClass*> arrayOfPieces);