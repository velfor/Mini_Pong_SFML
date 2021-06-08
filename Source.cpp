#include <SFML/Graphics.hpp>
#include "const.h"
#include "paddle.h"
#include "ball.h"

int main()
{
    
    sf::RenderWindow window(
        sf::VideoMode(windowWidth, windowHeight),
        "Mini Pong");
    Paddle paddle(windowWidth/2, windowHeight - 20);

    Ball ball(windowWidth / 2, windowHeight / 2);

    while (window.isOpen())
    {
        //Обработка ввода
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
        //Update игровых объектов
        paddle.update();
        ball.update(paddle);
        //Отрисовка
        window.clear();
        window.draw(paddle.getShape());
        window.draw(ball.getShape());
        window.display();
    }

    return 0;
}