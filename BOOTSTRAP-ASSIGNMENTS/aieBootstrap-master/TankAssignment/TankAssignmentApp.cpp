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

	List = new SceneObject();

	//load sprites in
	m_tank.load("../bin/textures/tank.png");
	m_turret.load("../bin/textures/gunturret.png");

	//attach turret to top of tank
	m_tank.addChild(&m_turret);

	//center the tank
	m_tank.setPosition(getWindowWidth() / 2.f, getWindowHeight() / 2.f);	

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	return true;
}

void TankAssignmentApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete List;
	delete new_bullet;
}

void TankAssignmentApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	m_tank.update(deltaTime);
	m_tank.updateTransform();


	//=======UpdateInList=====
	List->updateTransform();
	//=======UpdateInList=====


	//=======Apply Friction========
	m_tank.ApplyFric();
	m_turret.ApplyFric();
	//=======Apply Friction========


	timer = timer - deltaTime * 2;
	//Purpose: To Destroy the bullets, upon a timer
	if (timer < 5)
	{
		timer = 10;
		for (int i = 5; i < sizeof(List); i++)
		{
			List->removeChild(new_bullet);
		}
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{

		Matrix3 tank_vel;

		tank_vel.translation.m_y = 20 * deltaTime;//acceleration upwards = 20
		m_tank.IncVel(tank_vel);//increases upon update
	}
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		Matrix3 tank_rot;

		tank_rot.setRotateZ(deltaTime);
		m_tank.IncVel(tank_rot); //increases upon update

	}
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		Matrix3 tank_vel;

		tank_vel.translation.m_y = -20 * deltaTime;//acceleration downwards = 20(-20)
		m_tank.IncVel(tank_vel);//increases upon update
	}
	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		Matrix3 tank_rot;

		tank_rot.setRotateZ(-deltaTime);
		m_tank.IncVel(tank_rot);//increases upon update
	}
	if (input->isKeyDown(aie::INPUT_KEY_Q))
	{
		Matrix3 turret_rot;

		turret_rot.setRotateZ(deltaTime);
		m_turret.IncVel(turret_rot);//increases upon update
	}
	if (input->isKeyDown(aie::INPUT_KEY_E))
	{
		Matrix3 turret_rot;

		turret_rot.setRotateZ(-deltaTime);
		m_turret.IncVel(turret_rot);//increases upon update
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		Matrix3 velocity;
		velocity.translation.m_y = 2;

		new_bullet = new SpriteObject(); //create new bullet

		new_bullet->load("../bin/textures/m_bullet.png");//adds texture

		//insert into List
		List->addChild(new_bullet);
		new_bullet->setRotate(atan2f(m_turret.public_getGlobalTransform()[0][1], m_turret.public_getGlobalTransform()[0][0])); //set where it's pointing according to cannon
		
		Matrix3 gunPoint;

		gunPoint = m_turret.getLocalTransform();
		gunPoint.translation.m_y += new_bullet->GetTexture()->getHeight(); //+ the height
		gunPoint = m_turret.public_getGlobalTransform() * gunPoint;
		new_bullet->setPosition(gunPoint[2][0], gunPoint[2][1]); //position of bullet to be at gunpoint
		new_bullet->SetVel(velocity); //sets velocity accordingly through each update
	}
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