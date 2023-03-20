#pragma once
#include "SDL.h"
#include "TextureManager.hpp"

class Object {
public:

	Object();
	Object(const char* texturesheet);
	~Object();

	virtual void Init(const char* texturesheet, int width, int height, int xpos, int ypos);

	virtual void Update();
	virtual void Render();

	SDL_Rect srcRect, destRect;

protected:
	SDL_Texture* objTexture;
};