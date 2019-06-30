#pragma once
#include "AgentClass.h"
#include <Input.h>
#include <Vector2.h>

class Behaviour
{
public:

	// empty constructors and destructors fore base class
	Behaviour() {};
	virtual ~Behaviour() {};

	// pure virtual function for executing the behaviour
	virtual Vector2 Update(Agent* agent, float deltaTime) = 0;
};

class KeyboardBehaviour : public Behaviour
{
public:
	KeyboardBehaviour();
	virtual ~KeyboardBehaviour();

	virtual Vector2 Update(Agent* agent, float deltaTime);
};