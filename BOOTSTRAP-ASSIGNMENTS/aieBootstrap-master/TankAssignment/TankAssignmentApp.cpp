#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "TankAssignmentApp.h"
#include <math.h>

TankAssignmentApp::TankAssignmentApp() {

}

TankAssignmentApp::~TankAssignmentApp() {

}

bool TankAssignmentApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	//load sprites in
	m_tank.load("../bin/textures/tank.png");
	m_turret.load("../bin/textures/gunturret.png");

	//attach turret to top of tank
	m_tank.addChild(&m_turret);
	
	//m_tank.getPosition(); //retrieves current tank position;

	//m_bullet.setPosition = m_tank.getPosition();

	//center the tank
	m_tank.setPosition(getWindowWidth() / 2.f, getWindowHeight() / 2.f);	
	//m_bullet.setPosition(getWindowWidth() / 2.f, getWindowHeight() / 2.f);	
	//Tracker = m_tank.setPosition(getWindowHeight() / 2.f, getWindowHeight()/2.f);

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	return true;
}

void TankAssignmentApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void TankAssignmentApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	m_tank.update(deltaTime);
	m_tank.updateTransform();
	bulletFired = false;

	//m_bullet.ApplyVel();
	List->updateTransform();
	//new_bullet->ApplyVel();
	
	m_tank.ApplyFric();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		Matrix3 tank_vel;

		tank_vel.translation.m_y = 20 * deltaTime;
		m_tank.IncVel(tank_vel);
		//auto facing = m_tank.getLocalTransform()[1] * deltaTime *300;
		//m_tank.translate(facing.m_x, facing.m_y);//facing.x, facing.y)
	}
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		Matrix3 tank_rot;

		tank_rot.setRotateZ(deltaTime);
		m_tank.IncVel(tank_rot);

	}
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		Matrix3 tank_vel;

		tank_vel.translation.m_y = -20 * deltaTime;
		m_tank.IncVel(tank_vel);
		//auto facing = m_tank.getLocalTransform()[1] * deltaTime * -300;
		//m_tank.translate(facing.m_x, facing.m_y);//facing.x, facing.y)
	}
	if (input->isKeyDown(aie::INPUT_KEY_D))
	{

		Matrix3 tank_rot;

		tank_rot.setRotateZ(-deltaTime);
		m_tank.IncVel(tank_rot);

		//m_tank.rotate(-deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_Q))
	{
		m_turret.rotate(deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_E))
	{
		m_turret.rotate(-deltaTime);
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		Matrix3 velocity;
		velocity.translation.m_y = 20;

		new_bullet = new SpriteObject();

		new_bullet->load("../bin/textures/m_bullet.png");

		//insert into tree
		List->addChild(new_bullet);
		//tree->insert(new_bullet);

		new_bullet->setRotate(atan2f(m_turret.DgetGlobalTransform()[0][1], m_turret.DgetGlobalTransform()[0][0]));
		new_bullet->setPosition()
		new_bullet->setPosition(m_turret.DgetGlobalTransform()[2][0], m_turret.DgetGlobalTransform()[2][1]); //position

		new_bullet->SetVel(velocity);

		//m_bullet.setRotate(atan2f(m_turret.DgetGlobalTransform()[0][1], m_turret.DgetGlobalTransform()[0][0])); //radian 
		//m_bullet.setPosition(m_tank.DgetGlobalTransform()[2][0], m_tank.DgetGlobalTransform()[2][1]); //position
		
		//m_bullet.SetVel(velocity);
		
		
		//new_bullet;//set transform matrix
		//transform matrix includes
		//location - 
		//rotation -
		//speed -

		//SpriteObject *head = nullptr;

		//bullet = m_turret.getLocalTransform();
		////bullet speed = 10f;
		//bullet.setRotateZ(2.02315561);
		//
		//bullet.c_x *= speed;
		//bullet.c_y *= speed;
		//bullet.c_z *= speed;
		//m_bullet.setPosition(m_tank.getLocalTransform()[0][0], m_tank.getLocalTransform()[0][1]);




		//head = localTransform;
		//auto directionFacing = m_turret.getLocalTransform()[1] * deltaTime * 100;
		//new_bullet.translate(directionFacing.m_x, directionFacing.m_y);
		//auto facing = m_turret.getLocalTransform()[1] * deltaTime * 100; //moves with turret
		//bulletFired = true;
		//bulletFiredAnimate = true;
		//if(bulletFiredAnimate)
		//auto facing = m_turret.getLocalTransform()[1] * deltaTime * 100; //moving each frame upwards
		//m_bullet.translate(facing.m_x, facing.m_y); //facing up
	}
	//auto facing = m_turret.getLocalTransform()[1] * deltaTime * 100;

	//m_bullet.translate(facing.m_x, facing.m_y);

}

void TankAssignmentApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	
	// draw the tank
	m_tank.draw(m_2dRenderer);
	
	//m_bullet.draw(m_2dRenderer);
	//new_bullet->OnDraw(m_2dRenderer);

	List->draw(m_2dRenderer);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}