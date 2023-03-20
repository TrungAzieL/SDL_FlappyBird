#include "Game.hpp"
#include "TextureManager.hpp"
#include "Object_bird.hpp"
#include "Object_pole.hpp"
#include "Object_road.hpp"
#include "Collider.hpp"

Object background;
Object_road road[2];
Object_bird bird;
Object_pole pole_head[6],pole_head__rev[6], pole_body[6], pole_body__rev[6];

SDL_Rect rect, destBg, destBird;

Game::Game() {}

Game::~Game() {}

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

bool Game::isRunning = false;

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = 0;

	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 241, 200, 255, 255);
		}

		isRunning = true;
	}

	background.Init("assets/background.png", SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);

	bird.Init("assets/TuMoRau_bird__animation.png", 64, 64, 100, 200);

	road[0].Init("assets/road.png", 1008, 16, 0, 538);
	road[1].Init("assets/road.png", 1008, 16, 1008, 538);

	for (int i = 0; i < 6; ++i) {
		int height = pole_body[0].randomHeight();
		//height = pole_body__Height

		pole_head[i].Init("assets/pole_head.png", 100, 45, pole_head[i].getDiffWidth() * (i + 1), SCREEN_HEIGHT - ROAD_HEIGHT - height - 45);

		pole_body[i].Init("assets/pole_body.png", 100, height, pole_head[i].getDiffWidth() * (i + 1), SCREEN_HEIGHT - ROAD_HEIGHT - height);


		pole_head__rev[i].Init("assets/pole_head__rev.png", 100, 45, pole_head[i].getDiffWidth() * (i + 1), SCREEN_HEIGHT - ROAD_HEIGHT - height - pole_head[i].getDiffHeight() - 45);
		
		pole_body__rev[i].Init("assets/pole_body.png", 100, SCREEN_HEIGHT - ROAD_HEIGHT - height - pole_head[i].getDiffHeight() - 45, pole_head[i].getDiffWidth() * (i + 1), 0);

	}
}

void Game::handleEvents() {
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update() {
	bird.Update();
	
	for (int i = 0; i < 6; ++i) {
		SDL_Rect* poleShape[4] = { pole_body[i].getShape(), pole_head[i].getShape() , pole_body__rev[i].getShape() , pole_head__rev[i].getShape() };

		if (bird.checkCollider(poleShape)) {
			system("cls");
			printf("Collider! %d\n", i);                    
		}
		pole_body[i].Update();
		pole_head[i].Update();

		pole_body__rev[i].Update();
		pole_head__rev[i].Update();

		if (pole_head[i].destRect.x < pole_body[i].getDiffWidth() / -2 ) {

			pole_body[i].destRect.x = pole_body[i].getNewX();
			pole_body__rev[i].destRect.x = pole_body[i].getNewX();
			pole_head[i].destRect.x = pole_body[i].getNewX();
			pole_head__rev[i].destRect.x = pole_body[i].getNewX();

			int height = pole_body[0].randomHeight();

			pole_head[i].Update(SCREEN_HEIGHT - ROAD_HEIGHT - height - 45, 0);
			pole_body[i].Update(SCREEN_HEIGHT - ROAD_HEIGHT - height, 0);
			pole_body[i].Update(height, 1);

			pole_head__rev[i].Update(SCREEN_HEIGHT - ROAD_HEIGHT - height - pole_head[i].getDiffHeight() - 45, 0);
			pole_body__rev[i].Update(SCREEN_HEIGHT - ROAD_HEIGHT - height - pole_head[i].getDiffHeight() - 45, 1);
		}
	}

	road[0].Update();
	road[1].Update();
}

void Game::render() {
	SDL_RenderClear(renderer);

	background.Render();

	for (int i = 0; i < 6; ++i) {
		pole_body[i].Render();
		pole_head[i].Render();

		pole_body__rev[i].Render();
		pole_head__rev[i].Render();
	}

	road[0].Render();
	road[1].Render();

	bird.Render();

	SDL_RenderPresent(renderer);

}
 
void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}