#include "AgentClass.h"
Vector2 KeyboardBehaviour::Update(Agent * agent, float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();
	Vector2 force(0,0);

	if (input->isKeyDown(aie::INPUT_KEY_UP)) 
		force.m_y = 20.0f;
	else if (input->isKeyDown(aie::INPUT_KEY_DOWN)) 
		force.m_y = -20.0f;
	else if (input->isKeyDown(aie::INPUT_KEY_LEFT)) 
		force.m_x = -20.0f;
	else if (input->isKeyDown(aie::INPUT_KEY_RIGHT)) 
		force.m_x = 20.0f;

	return force;
}
