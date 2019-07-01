#pragma once
#include <vector>
#include "State.h"
#include "GameObject.h"

class State;
class GameObject;

class FiniteStateMachine 
{
public:
	FiniteStateMachine(int stateCount);
	virtual ~FiniteStateMachine();

	void addState(int id, State* newState);

	void forceState(int id);

	void update(GameObject * gameObject, float deltaTime);

protected:
	State* m_currentState = nullptr;
	std::vector<State*> m_states;
};


