#include "FlyCamera.h"

FlyCamera::FlyCamera()
{
	m_forwardKey = aie::INPUT_KEY_W;
	m_backwardKey = aie::INPUT_KEY_S;
	m_leftKey = aie::INPUT_KEY_A;
	m_rightKey = aie::INPUT_KEY_D;

	m_mouseButton = aie::INPUT_MOUSE_BUTTON_RIGHT;
}

FlyCamera::~FlyCamera()
{
}

void FlyCamera::update(float deltaTime)
{
	//	Get an instance of the AIE input module
	m_input = aie::Input::getInstance();

	// Movement
	if (m_input->isKeyDown(m_forwardKey)) 
	{
	}
}
