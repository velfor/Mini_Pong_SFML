#include "ball.h"
#include "const.h"
#include "paddle.h"
Ball::Ball(float startX, float startY) {
	position.x = startX;
	position.y = startY;
	ballShape.setSize(sf::Vector2f(10,10));
	ballShape.setPosition(position);
}
FloatRect Ball::getPosition() {
	return ballShape.getGlobalBounds();
}
RectangleShape Ball::getShape() { return ballShape; }
//отражение от левой и правой стены
void Ball::reboundSides() { speedX = -speedX; }
void Ball::reboundTopDown() { speedY = -speedY; }
void Ball::update(Paddle& paddle, int& score, int& lives) {
	
	position.x += speedX;
	position.y += speedY;
	ballShape.setPosition(position);
	//отражениe от верха
	if (getPosition().top < 0) {
		reboundTopDown();
		score++;
	}
	else
		//отражения слева и справа
		if (getPosition().left < 0 ||
			getPosition().left + 10 > windowWidth) 
			reboundSides();
	else
		// попали в платформу
		if (getPosition().intersects(paddle.getPosition())) {
			while (getPosition().intersects(paddle.getPosition()))
				position.y -= 10;
			reboundTopDown();
		}
	else
		// попали в нижний край
		if (getPosition().top + 10 > windowHeight) {
			reboundTopDown();
			lives--;
		}
	if (lives < 1) {
		ballShape.setPosition(400, 300);
		speedX = 0.f;
		speedY = 0.f;
	}
}