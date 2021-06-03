#include <SFML/Graphics.hpp>
#include "paddle.h"

int main()
{
    const int windowWidth = 800;
    const int windowHeight = 600;
    sf::RenderWindow window(
        sf::VideoMode(windowWidth, windowHeight),
        "Mini Pong");
    Paddle paddle(windowWidth/2, windowHeight - 20);

    while (window.isOpen())
    {
        //��������� �����
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)
            || Keyboard::isKeyPressed(Keyboard::A))
        {
            paddle.moveLeft();
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)
            || Keyboard::isKeyPressed(Keyboard::D))
        {
            paddle.moveRight();
        }
        //Update ������� ��������
        paddle.update();
        //���������
        window.clear();
        window.draw(paddle.getShape());
        window.display();
    }

    return 0;
}