#include "Window.h"

int main() {

	Window window;

	while (window.Running()) {
		
		window.Update();
		window.Draw();

	}

	return 0;

}