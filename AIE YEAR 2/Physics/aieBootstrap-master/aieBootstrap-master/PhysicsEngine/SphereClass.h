#pragma once
#include "RigidBodyClass.h"

class SphereClass : public RigidBodyClass
{
public:
	SphereClass(glm::vec2 position, glm::vec2 velocity, 
		float mass, float radius, float elasticity, float angularVelocity, float moment, glm::vec4 colour);

	SphereClass(glm::vec2 position, float speed, float angle,
		float mass, float radius, glm::vec4 colour);
	
	~SphereClass();

	virtual void makeGizmo();
	virtual bool checkCollision(PhysicsObject* pOther);


	float getRadius() { return m_radius; }
	glm::vec4 getColour() { return m_colour; }
	void setColour(glm::vec4 a_colour) { m_colour = a_colour; }

	//	To Track Score Functions
	float getTimeStored() { return m_timeUntilScore; }
	void incrementTimeStored() { m_timeUntilScore = m_timeUntilScore + 1; }
	void resetTimeStored() { m_timeUntilScore = 0; }
	
	//	To Track Striker
	void setThisToStriker() { isStriker = true; }
	bool isThisStriker() { return isStriker; }

	//collidable condition
	bool ifCollidable() { return m_collidable; }
	void setCollision(bool a_collision) { m_collidable = a_collision; }
	
	//	To Track Player Turn
	bool returnPlayerTurn() { return m_player; }
	void setPlayerTurn(bool a_condition) { m_player = a_condition; }
	
	//for continuous streak create bool for scored
	//then set it to the same one if resolution was true
	bool ifStreak() { return m_streak; }
	void setStreak(bool a_condition) { m_streak = a_condition; }

	//	create condition to place striker down on play area
	//	to start aiming and then shoot
	bool isPlaceble() { return m_placeable; }
	void setPlaceable(bool condition) { m_placeable = condition; }

	//	Sets piece to foul if in play area,
	//	so it can't be directly hit
	bool isFoul() { return m_foul; }
	void setFoul(bool a_condition) { m_foul = a_condition; }

	//	To Allow Collision To Set Other Foul Pieces to False
	//	In Scene
	void resetFoulPieces(bool a_condition) { m_resetFoulPieces = a_condition; }
	bool returnResetFoulPieces() { return m_resetFoulPieces; }

	// To Track Previous Variables
	void setPrevAng_vel(float a_ang_vel) { prev_angVel = a_ang_vel; }
	void setPrevRot(float a_rotation) { prev_rot = a_rotation; }
	void setPrevPos(glm::vec2 a_pos) { prev_pos = a_pos; }

	//	To Set Striker With INformation That it
	//	Is The Start Of The Turn
	void setStartTurn(bool a_condition) { m_startOfTurn = a_condition;}
	bool isitStartTurn() { return m_startOfTurn; }

	// To Rewind to previous status
	void rewindTime() { m_angularVelocity = prev_angVel; m_rotation = prev_rot; m_position = prev_pos; }

protected:
	//default
	float m_radius;
	glm::vec4 m_colour;

	//TO Track Striker
	bool isStriker = false;

	// Stores Time Here When Above Hole
	float m_timeUntilScore;

	//	if true player equal to 'PLAYER 1'
	//	if false player equal to 'PLAYER 2'
	bool m_player = true;

	//set Collision for Spheres
	bool m_collidable = true;

	//	placeable to start aim
	bool m_placeable;

	//	streak
	bool m_streak = false;

	//	sets peices to fouls
	bool m_foul = false;

	float prev_angVel = m_angularVelocity;
	float prev_rot = m_rotation;
	glm::vec2 prev_pos = m_position;

	bool m_resetFoulPieces = false;

	bool m_startOfTurn = false;
};

