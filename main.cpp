#include <iostream>
#include <SFML/Graphics.hpp>
#include "food.h"
#include "snake.h"
#include "vector"

#define WIDTH 50
#define HEIGHT 30
#define SIZE 16
#define W SIZE*WIDTH
#define H SIZE*HEIGHT


Snake snake({WIDTH/2 , HEIGHT/2});
Food food;

int main(){

    sf::Clock clock;
    double timer = 0, delay = 0.1;
    
    sf::RenderWindow window(sf::VideoMode(W,H),"Snake Game");


    sf::Texture t1,t2;
    t1.loadFromFile("images/green.png");
    t2.loadFromFile("images/red.png");


    sf::Sprite sprite1(t1);
    sf::Sprite sprite2(t2);


    while (window.isOpen()){

        double time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        sf::Event e;

        while (window.pollEvent(e)){
            if(e.type == sf::Event::Closed){
                window.close();
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            snake.setDir('u');
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            snake.setDir('d');
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            snake.setDir('l');
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            snake.setDir('r');
        }

        if(timer > delay){
            snake.moveSnake();
            timer = 0;
            if(snake.eaten(food)){
                snake.grow();
                food.genFood();
            }
        }


        window.clear();

        for (size_t i = 0; i < WIDTH; i++){
            for (size_t j = 0; j < HEIGHT; j++){
                sprite1.setPosition(i*SIZE,j*SIZE);
                window.draw(sprite1);
            }
            
        }

        std::vector<COORD> snakeBody = snake.getSnakeBody();
        for (size_t i = 0; i < snakeBody.size(); i++){
            sprite2.setPosition(snakeBody[i].x * SIZE ,snakeBody[i].y * SIZE);
            window.draw(sprite2);
        }
        

        sprite2.setPosition(food.getFood().x * SIZE,food.getFood().y * SIZE);
        window.draw(sprite2);

        if(snake.collided()){
            window.clear();
            sf::Text t;
            t.setString("GAME OVER");
            sf::Font f;
            if(!f.loadFromFile("images/arial.ttf")){
                std::cout << "Unable to load font";
            }
            t.setFont(f);
            t.setCharacterSize(40);
            t.setStyle(sf::Text::Bold);
            t.setPosition(W/3,H/3);

            for (size_t i = 0; i < WIDTH; i++){
                for (size_t j = 0; j < HEIGHT; j++){
                    sprite1.setPosition(i*SIZE,j*SIZE);
                    window.draw(sprite1);
                }
                
            }
            window.draw(t);
            window.display();
            system("sleep 3");
            break;
            
        }


        window.display();
        
    }
    

    return 0;
}