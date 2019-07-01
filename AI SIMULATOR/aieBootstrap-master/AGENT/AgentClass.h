#pragma once
#include <Vector2.h>
#include <Renderer2D.h>
#include <vector>


class Agent
{
public:
	Agent();
	virtual ~Agent();

	virtual void Update(float deltaTime); //update the agent and its behaviours each frame

	virtual void Draw(aie::Renderer2D* renderer); //draws

	void AddBehaviour(Behaviour* behaviour); //adds that behaviour to Agent

	void setPosition(Vector2 position);//sets vector2 to position
	Vector2 getPosition(); //returns position

	void setVelocity(vector2 velocity); //sets vector2 to velocity
	void getVelocity(); //returns velocity

protected:
	std::vector<Behaviour*>m_behaviourList;

	Vector2 m_Position;
	Vector2 m_Velocity;
};