#pragma once
#include "Object.hpp"

class Object_road : public Object_pole{
public:
	void Update() override {
		destRect.x -= speed;
		if (destRect.x < -1006) {
			destRect.x = 1006;
		}
	}

};