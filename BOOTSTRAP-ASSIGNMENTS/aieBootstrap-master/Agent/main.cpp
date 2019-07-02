#include "AgentApp.h"
#include <time.h>

int main() {
	
	// allocation
	auto app = new AgentApp();
	srand(time(NULL));
	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}