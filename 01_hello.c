#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *argv[]) {
	// Window being rendered to
	SDL_Window* window = NULL;
	// Surface contained by window
	SDL_Surface* screenSurface = NULL;

	// Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else {
		window = SDL_CreateWindow(
				"SDL Tutorial",
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				SCREEN_WIDTH,
				SCREEN_HEIGHT,
				SDL_WINDOW_SHOWN
				);
		if(!window) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else {
			// Get window surface
			screenSurface = SDL_GetWindowSurface(window);
			// Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
			// Update the surface
			SDL_UpdateWindowSurface(window);
			// Hack to get window to stay
			SDL_Event e;
			int quit = 0;
			while(!quit) {
				while(SDL_PollEvent(&e)) {
					if(e.type == SQL_QUIT) {
						quit = 0;
					}
				}
			}
		}
	}

	// Destroy window
	SDL_DestroyWindow(window);
	// Quit SDL subsystems
	SDL_Quit();

	return 0;
}
