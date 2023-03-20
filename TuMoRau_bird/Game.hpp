#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Game {
public:

	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() {
		return isRunning;
	}

	static SDL_Event event;
	static bool isRunning;
	static SDL_Renderer* renderer;

	const int SCREEN_WIDTH = 992;
	const int SCREEN_HEIGHT = 640;

	const int ROAD_HEIGHT = 116;
	const int ROAD_WIDTH = SCREEN_WIDTH;

	const int SKY_HEIGHT = SCREEN_WIDTH - ROAD_HEIGHT;
	const int SKY_WIDTH = SCREEN_WIDTH;

private:
	SDL_Window* window;
};