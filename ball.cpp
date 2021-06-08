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
//��������� �� ����� � ������ �����
void Ball::reboundSides() { speedX = -speedX; }
void Ball::reboundTopDown() { speedY = -speedY; }
void Ball::update(Paddle& paddle) {
	position.x += speedX;
	position.y += speedY;
	ballShape.setPosition(position);
	//��������e �� �����, ���� � �������
	if (getPosition().top < 0 ||
		getPosition().top + 10 > windowHeight)) 
		reboundTopDown();
	else
		//��������� ����� � ������
		if (getPosition().left < 0 ||
			getPosition().left + 10 > windowWidth) 
			reboundSides();
	else
		if (getPosition().intersects(paddle.getPosition())) {
			while (getPosition().intersects(paddle.getPosition()))
				position.y--;
			reboundTopDown();
		}

	

}