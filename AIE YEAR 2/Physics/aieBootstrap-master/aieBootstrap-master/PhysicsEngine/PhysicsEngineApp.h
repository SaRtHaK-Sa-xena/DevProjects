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

	//	physics scene
	PhysicsScene* m_physicsScene;

	SphereClass* rocket_Ship;
	
	// Being Used
	//SphereClass* sphere;
	
	SphereClass* sphere = new SphereClass(glm::vec2(-10, -240), glm::vec2(0, 0), 1, (5*5), 0.6, 0, 1, glm::vec4(0, 0, 0, 0));

	SphereClass* centreSphere = new SphereClass(glm::vec2(-10, 5), glm::vec2(0, 0), 1, 3*5, 0.6, 0, 1, glm::vec4(1, 0, 0, 1));

	//top_mid left and right
	SphereClass* sphereInner1 = new SphereClass(glm::vec2(25, 35), glm::vec2(0, 0), 1, 3*5, 0.6, 0, 1, glm::vec4(0, 1, 1, 1));
	SphereClass* sphereInner2 = new SphereClass(glm::vec2(-45, 35), glm::vec2(0, 0), 1, 3*5, 0.6, 0, 1, glm::vec4(0, 1, 1, 1));


	//bottom_mid left and right
	SphereClass* sphereInner3 = new SphereClass(glm::vec2(25, -35), glm::vec2(0, 0), 1, 3 * 5, 0.6, 0, 1, glm::vec4(0, 1, 1, 1));
	SphereClass* sphereInner4 = new SphereClass(glm::vec2(-45, -35), glm::vec2(0, 0), 1, 3 * 5, 0.6, 0, 1, glm::vec4(0, 1, 1, 1));

	//top
	SphereClass* sphereInner5 = new SphereClass(glm::vec2(-10, 50), glm::vec2(0, 0), 1, 3 * 5, 0.6, 0, 1, glm::vec4(0, 1, 1, 1));

	//right_mid
	SphereClass* sphereInner6 = new SphereClass(glm::vec2(50, 0), glm::vec2(0, 0), 1, 3 * 5, 0.6, 0, 1, glm::vec4(0, 1, 1, 1));

	//left_mid
	SphereClass* sphereInner7 = new SphereClass(glm::vec2(-70, 0), glm::vec2(0, 0), 1, 3 * 5, 0.6, 0, 1, glm::vec4(0, 1, 1, 1));

	//bottom
	SphereClass* sphereInner8 = new SphereClass(glm::vec2(-10, -60), glm::vec2(0, 0), 1, 3 * 5, 0.6, 0, 1, glm::vec4(0, 1, 1, 1));

	AABBClass* box1;

	AABBClass* topLeftHole;
	AABBClass* topRightHole;

	AABBClass* bottomLeftHole;
	AABBClass* bottomRightHole;

	SphereClass* striker;

	SphereClass* mousePointer = new SphereClass(glm::vec2(0, 0), 0, 0, 1, 2, glm::vec4(1, 0, 1, 1));

	glm::vec2 mouseCurrentPosition;

	glm::vec2 r_end;

	// checks if player can shoot
	bool playerTurnActivated;

	// Display Player 1 Wins
	bool player1_winScreen = false;
	
	// Display Player 2 Wins
	bool player2_winScreen = false;


protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	//background sprite
	aie::Texture* m_backgroundTexture; 
	
	// white piece sprite
	aie::Texture* m_whiteCoinTexture;

	//objects in scene
	std::vector<SphereClass*> CoinsInScene;

	//Score Tracker for players
	int ScorePlayer1;
	int ScorePlayer2;

};

void setFoulPieces(std::vector<SphereClass*> arrayOfPieces);