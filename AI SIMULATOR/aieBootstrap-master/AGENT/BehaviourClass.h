#pragma once
#include <Vector2.h>

//forward reference
class Agent;


class Behaviour
{
public:

	Behaviour();
	virtual ~Behaviour();

	virtual Vector2 Update(Agent* agent, float deltaTime) = 0;
};

class KeyboardBehaviour : public Behaviour
{
public:
	KeyboardBehaviour();
	virtual ~KeyboardBehaviour();

	virtual Vector2 Update(Agent* agent, float deltaTime);
};