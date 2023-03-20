#pragma once
#include "Object.hpp"

class Object_bird : public Object {
public:
	Object_bird() {
		deg = 0;
		frames = 0;
		delay = 0;
		animation = 0;
	};

	void Init(const char* texturesheet, int width, int height, int xpos, int ypos) override {
		objTexture = TextureManager::LoadTexture(texturesheet);
		srcRect.x = 0;
		srcRect.y = 0;

		srcRect.h = 32;
		srcRect.w = 32;

		destRect.h = height;
		destRect.w = width;

		destRect.x = xpos;
		destRect.y = ypos;
	}

	bool checkJump() {
		if (Game::event.type == SDL_KEYDOWN) {
			if (Game::event.key.keysym.sym == SDLK_SPACE) {
				deg = -20.00;
				frames = 8;
				delay = 10;
				return true;
			}
		}
		return false;
	}

	void Update() override {
		animation++;
		if (animation > 5) {
			srcRect.x += 32;
			animation = 0;
		}

		if (srcRect.x > 32 * 3) {
			srcRect.x = 0;
		}

		if (frames >= 0)
		{
			destRect.y -= 2 * frames;
			frames--;

			if (checkJump())
				return;
		}

		if (checkJump())
			return;

		if (delay < -1) {
			deg -= 10.00 / frames;
			if (deg > 90.00) deg = 90.00;
			if (deg < -20.00) deg = -20.00;
		}

		delay--;
		if (delay >= -2) {
			return;
		}

		destRect.y += (frames + 1) * -3;
		frames--;

		if (frames <= -4) {
			frames = -4;
		}

	}

	void Render() override {
		if (destRect.y < 0) destRect.y = 0;
		if (destRect.y > 640 - 64 - 110) destRect.y = 640 - 64 - 110;
		TextureManager::Draw(objTexture, srcRect, destRect, deg);
	}

private:
	double deg;
	int delay;
	int frames;

	int animation;
};