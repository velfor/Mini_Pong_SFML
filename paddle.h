#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Paddle {
private:
	RectangleShape paddleShape;
	Vector2f position;
	float paddleSpeed = 0.5f;
	float paddleWidth = 50.f;
	float paddleHeight = 5.f;

public:
	Paddle(float, float);
	FloatRect getPosition();
	RectangleShape getShape();
	void moveLeft();
	void moveRight();
	void update();
};