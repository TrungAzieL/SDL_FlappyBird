#pragma once
#include "SDL.h"

class Collider {
public:
	bool collider(const SDL_Rect* A, const SDL_Rect* B) {
		return SDL_IntersectRect(A, B, NULL);
	}
};