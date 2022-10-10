#include "snake.h"

#define WIDTH 50
#define HEIGHT 30


Snake::Snake(COORD pos){
    this->pos = pos;
    len = 1;
    snakeBody.push_back(pos);
};

COORD Snake::getPos(){
    return pos;
};

void Snake::setDir(int d){
    dir = d;
};

void Snake::moveSnake(){
    switch (dir){
    case 'u': pos.y--;break;
    case 'd': pos.y++;break;
    case 'l': pos.x--;break;
    case 'r': pos.x++;break;
    }
    snakeBody.push_back(pos);
    if(snakeBody.size() > len){
        snakeBody.erase(snakeBody.begin());
    }
}

bool Snake::collided(){
    if(pos.x == 0 || pos.x == WIDTH + 1 || pos.y == 0 || pos.y == HEIGHT + 1){
        return 1;
    }

    return 0;
}

bool Snake::eaten(Food &food){
    if(pos.x == food.getFood().x && pos.y == food.getFood().y){
        return 1;
    }

    return 0;
}

void Snake::grow(){
    len++;
}

std::vector<COORD> Snake::getSnakeBody(){
    return snakeBody;
}

int Snake::getLen(){
    return len;
}