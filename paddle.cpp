#include "paddle.h"
#include "const.h"

Paddle::Paddle(float startX, float startY) {
	position.x = startX;
	position.y = startY;
	paddleShape.setSize(sf::Vector2f(paddleWidth, paddleHeight));
	paddleShape.setPosition(position);
}
FloatRect Paddle::getPosition() {
	return paddleShape.getGlobalBounds();
}
RectangleShape Paddle::getShape() {
	return paddleShape;
}
void Paddle::moveLeft() {
	position.x -= paddleSpeed;
}
void Paddle::moveRight() {
	position.x += paddleSpeed;
}
void Paddle::update() {
	if (position.x < 0) position.x = 0;
	else
		if (position.x > windowWidth - 50)
			position.x = windowWidth - 50;
	paddleShape.setPosition(position);
}