#pragma once
#include <SFML/Graphics.hpp>
#include "paddle.h"

using namespace sf;

class Ball {
private:
	Vector2f position;
	RectangleShape ballShape;
	float speedX = 0.2f;
	float speedY = 0.2f;
public:
	Ball(float, float);
	FloatRect getPosition();
	RectangleShape getShape();
	void reboundSides();//отражение от левой и правой стены
	void reboundTopDown();
	void update(Paddle&);
};