#include "_2020PhysicsRevisionApp.h"

int main() {
	
	// allocation
	auto app = new _2020PhysicsRevisionApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}