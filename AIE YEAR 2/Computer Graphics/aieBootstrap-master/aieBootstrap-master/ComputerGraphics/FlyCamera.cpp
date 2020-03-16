#include "FlyCamera.h"

void FlyCamera::update(float deltaTime)
{
	//	Get an instance of the AIE input module
	m_input = aie::Input::getInstance();

	// Movement
	if (m_input->isKeyDown(m_forwardKey)) 
	{
	}
}
