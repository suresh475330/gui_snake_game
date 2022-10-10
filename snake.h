#ifndef SNAKE_H     // if not already defined is meaing
#define SNAKE_H
#include "vector"
#include "food.h"

#define WIDTH 50
#define HEIGHT 30

struct COORD{
    int x;
    int y;
};


class Snake{
private:
    COORD pos;
    int len;
    int dir;
    std::vector<COORD> snakeBody;

public:
    Snake(COORD pos);
    COORD getPos();
    void setDir(int d);
    void moveSnake();
    bool collided();
    bool eaten(Food &food);
    void grow();
    std::vector<COORD> getSnakeBody();

    int getLen();
};

#endif // SNAKE_H