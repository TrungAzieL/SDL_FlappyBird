#pragma once
#include "Game.hpp"
#include "Object.hpp"

class Object_pole : public Object {
public:
	void Update() override {
		destRect.x -= speed;
	}

	void Update(int newValue, bool changeHeight) {
		if (changeHeight) destRect.h = newValue;
		else destRect.y = newValue;
	}

	int randomHeight() {
		int height = ((int)rand() % 250) + 20;
		return	height;
	}

	int getDiffHeight() {
		return diffHeight;
	}

	int getDiffWidth() {
		return diffWidth;
	}

	int getNewX() {
		return resetX;
	}


private:
	const int diffHeight = 200;
	const int diffWidth = 300;
	const int resetX = diffWidth * 6 - diffWidth / 2;

protected:
	const int speed = 2;

};