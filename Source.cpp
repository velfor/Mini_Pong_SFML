#include <SFML/Graphics.hpp>
#include "const.h"
#include "paddle.h"
#include "ball.h"
#include <sstream>

int main()
{
    int score = 0, lives = 3;
    sf::RenderWindow window(
        sf::VideoMode(windowWidth, windowHeight),
        "Mini Pong");
    Paddle paddle(windowWidth/2, windowHeight - 20);
    Ball ball(windowWidth / 2, windowHeight / 2);

    Text inform;
    Font font;
    font.loadFromFile("DS-DIGI.TTF");
    inform.setFont(font);
    inform.setCharacterSize(18);
    inform.setFillColor(Color::White);

    Text gameOver;
    gameOver.setFont(font);
    gameOver.setCharacterSize(48);
    gameOver.setFillColor(Color::White);
    gameOver.setPosition(300,300);
    gameOver.setString("");

    std::stringstream temp;

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
        ball.update(paddle, score, lives);
        temp.str("");
        temp << "Score: " << score << "\t\tLives: "<< lives;
        inform.setString(temp.str());
        if (lives == 0) {
            gameOver.setString("Game Over");
        }
        //Отрисовка
        window.clear();
        window.draw(paddle.getShape());
        window.draw(ball.getShape());
        window.draw(inform);
        window.draw(gameOver);
        window.display();
    }

    return 0;
}