#include "Object.hpp"

Object::Object() {
};

Object::~Object() {

}

void Object::Init(const char* texturesheet, int width, int height, int xpos, int ypos) {
	objTexture = TextureManager::LoadTexture(texturesheet);
	srcRect.x = 0;
	srcRect.y = 0;

	srcRect.h = height;
	srcRect.w = width;

	destRect.h = height;
	destRect.w = width;

	destRect.x = xpos;
	destRect.y = ypos;
}

void Object::Update() {
	
}

void Object::Render() {
	TextureManager::Draw(objTexture, srcRect, destRect, 0);
}