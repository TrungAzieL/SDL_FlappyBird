#include "Game.hpp"
#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* texture) {
	SDL_Surface* tmpSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	return tex;
}


void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, double deg)
{
	SDL_RenderCopyEx(Game::renderer, tex, &src, &dest, deg, NULL, SDL_FLIP_NONE);
}