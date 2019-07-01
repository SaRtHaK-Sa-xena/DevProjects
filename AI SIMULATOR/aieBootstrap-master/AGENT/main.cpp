#include "AGENTApp.h"

int main() {
	
	// allocation
	auto app = new AGENTApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}