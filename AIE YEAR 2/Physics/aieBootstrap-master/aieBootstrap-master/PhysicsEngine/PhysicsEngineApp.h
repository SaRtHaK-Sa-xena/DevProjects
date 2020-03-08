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

	//	player turn
	void startPhase();
	
	//	game turn
	void gamePhase();

	//	displayed after 
	//	either player wins
	void winPhase();

	//	Reset Pieces
	void reset();

	//	physics scene
	PhysicsScene* m_physicsScene;
	
	//Corner Pockets===========
	AABBClass* topLeftHole;
	AABBClass* topRightHole;
	AABBClass* bottomLeftHole;
	AABBClass* bottomRightHole;
	//Corner Pockets===========

	//Obstacle Boxes===========
	AABBClass* midLeftObs;
	AABBClass* midRightObs;
	//Obstacle Boxes===========

	glm::vec2 mouseCurrentPosition;

	// checks if player can shoot
	bool playerTurnActivated;

	// Display Player 1 Wins
	bool player1_winScreen = false;
	
	// Display Player 2 Wins
	bool player2_winScreen = false;


protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Renderer2D*	m_2dRendererGizmos;
	aie::Renderer2D*	m_menuRenderer;
	aie::Font*			m_font;

	//	background sprite
	aie::Texture* m_backgroundTexture; 
	
	//  white piece sprite
	aie::Texture* m_whiteCoinTexture;

	//  white piece foul sprite
	aie::Texture* m_whiteCoinFoulTexture;

	//  obstacles sprite
	aie::Texture* m_obstacleTexture;

	//  striker sprite
	aie::Texture* m_strikerTexture;

	//	player turn 1 header sprite
	aie::Texture* m_player1_header;

	//	player turn 2 header sprite
	aie::Texture* m_player2_header;

	//	menu sprite
	aie::Texture* m_menu;

	//	instruction sprite
	aie::Texture* m_instructions;

	//	instructions_txt sprite
	aie::Texture* m_instructionsText;

	//	exit_txt sprite
	aie::Texture* m_exitText;

	//objects in scene
	std::vector<SphereClass*> CoinsInScene;

	//	Score Tracker for players
	int ScorePlayer1 = 0;
	int ScorePlayer2 = 0;

	//	alpha_values
	float alpha_value = 0.1;

	//	sprite scalar value
	float sprite_scalar = 1;

	//	bool to track if line will be displayed red
	//	during Draw Function
	bool invalidAim = false;
	

	//	bool to track if the line will be drawn at max
	bool maxLine = false;

	//	bool to track if alpha levels need to be modified
	bool modify_alpha = true;

	//	bool to track the new clamp point
	bool clampHigh = true;

	//	bool to track the new clamp point for sprites
	bool clamp_spriteHigh = true;

	//	draw playerHeader
	bool drawHeader = true;

	//	draw menu
	bool drawMenu = false;

	//	draw instructions
	bool switchToInstructions = false;

	//	draw instructions text scaled
	bool drawInstructionsScaled = false;

	//	draw exit text scaled
	bool drawExitScaled = false;

	//Striker To be used
	SphereClass* sphere = new SphereClass(glm::vec2(-10, -240), glm::vec2(0, 0), 2, (3.5 * 6), 0.6, 0, 1, glm::vec4(0, 0, 0, 0));

	//Centre Sphere
	SphereClass * centreSphere = new SphereClass(glm::vec2(-10, 5), glm::vec2(0, 0), 1, 3 * 6, 0.3, 0, 1, glm::vec4(1, 0, 0, 1));

	//top_mid left and right
	SphereClass * sphereInner1 = new SphereClass(glm::vec2(25, 35), glm::vec2(0, 0), 1, 3 * 6, 0.3, 0, 1, glm::vec4(0, 1, 1, 1));
	SphereClass * sphereInner2 = new SphereClass(glm::vec2(-45, 35), glm::vec2(0, 0), 1, 3 * 6, 0.3, 0, 1, glm::vec4(0, 1, 1, 1));


	//bottom_mid left and right
	SphereClass * sphereInner3 = new SphereClass(glm::vec2(25, -35), glm::vec2(0, 0), 1, 3 * 6, 0.3, 0, 1, glm::vec4(0, 1, 1, 1));
	SphereClass * sphereInner4 = new SphereClass(glm::vec2(-45, -35), glm::vec2(0, 0), 1, 3 * 6, 0.3, 0, 1, glm::vec4(0, 1, 1, 1));

	//top
	SphereClass * sphereInner5 = new SphereClass(glm::vec2(-10, 50), glm::vec2(0, 0), 1, 3 * 6, 0.3, 0, 1, glm::vec4(0, 1, 1, 1));

	//right_mid
	SphereClass * sphereInner6 = new SphereClass(glm::vec2(50, 0), glm::vec2(0, 0), 1, 3 * 6, 0.3, 0, 1, glm::vec4(0, 1, 1, 1));

	//left_mid
	SphereClass * sphereInner7 = new SphereClass(glm::vec2(-70, 0), glm::vec2(0, 0), 1, 3 * 6, 0.3, 0, 1, glm::vec4(0, 1, 1, 1));

	//bottom
	SphereClass * sphereInner8 = new SphereClass(glm::vec2(-10, -60), glm::vec2(0, 0), 1, 3 * 6, 0.3, 0, 1, glm::vec4(0, 1, 1, 1));

};

void setFoulPieces(std::vector<SphereClass*> arrayOfPieces);
void clearCoins(PhysicsScene* currentScene, std::vector<SphereClass*> arrayOfPieces);
