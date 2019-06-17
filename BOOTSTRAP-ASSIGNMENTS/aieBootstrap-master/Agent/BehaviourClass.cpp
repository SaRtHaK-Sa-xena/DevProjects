#include "BehaviourClass.h"

Vector2 KeyboardBehaviour::Update(Agent * agent, float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();
	Vector2 force;

	if (input->isKeyDown(aie::INPUT_KEY_UP)) force.y = 500.0f;
	if (input->isKeyDown(aie::INPUT_KEY_DOWN)) force.y = -500.0f;
	if (input->isKeyDown(aie::INPUT_KEY_LEFT)) force.x = -500.0f;
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT)) force.x = 500.0f;
}
