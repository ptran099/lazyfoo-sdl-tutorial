#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char* argv[]) {
	// Window we'll render to
	SDL_Window* window = NULL;
	// Surface contained by window
	SDL_Surface *screenSurface = NULL;

	// Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
	}
	else {
		// Create window
	}
}
