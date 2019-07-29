#pragma once
//#include "AgentClass.h"
#include <Input.h>
#include <Vector2.h>

class Agent;

class Behaviour
{
public:

	// empty constructors and destructors for base class
	Behaviour() {};
	virtual ~Behaviour() {};

	// pure virtual function for executing the behaviour
	virtual Vector2 Update(Agent* agent, float deltaTime) = 0;

protected:
	float speed = 200; //sets the speed of enemy 
};

class KeyboardBehaviour : public Behaviour
{
public:
	KeyboardBehaviour() {};
	virtual ~KeyboardBehaviour() {};

	virtual Vector2 Update(Agent* agent, float deltaTime); //calls movement for the enemy
};