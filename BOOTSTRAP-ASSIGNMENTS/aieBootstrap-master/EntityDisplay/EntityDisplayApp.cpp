//Project 2
#include "EntityDisplayApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <Windows.h>
#include <iostream>

EntityDisplayApp::EntityDisplayApp() {

}

EntityDisplayApp::~EntityDisplayApp() {

}

bool EntityDisplayApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);

	fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"MySharedMemory");
	data = (Entity*)MapViewOfFile(fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(Entity));


	setBackgroundColour(1, 1, 1);

	return true;
}

void EntityDisplayApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	UnmapViewOfFile(data);
	CloseHandle(fileHandle);
}

void EntityDisplayApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	//Used For Testing In Debug
	//==================TESTING====================
	// write out what is in the memory blocks
	/*std::cout << "MyData = { ";
	std::cout << data->b << ", ";
	std::cout << data->g << ", ";
	std::cout << data->r << ", ";
	std::cout << data->rotation << ", ";
	std::cout << data->size << ", ";
	std::cout << data->speed << ", ";
	std::cout << " };" << std::endl;*/
	//================TESTING========================
}

void EntityDisplayApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw entities
	for (auto& entity : m_entities) {
		m_2dRenderer->setRenderColour(entity.r, entity.g, entity.b);
		m_2dRenderer->drawBox(entity.x, entity.y, entity.size, entity.size, entity.rotation);
	}
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}