#include "Simon___AssignmentApp.h"

int main() {
	
	// allocation
	auto app = new Simon___AssignmentApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}