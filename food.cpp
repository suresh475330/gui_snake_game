#include "food.h"
#include "ctime"
#include "stdlib.h"

#define WIDTH 50
#define HEIGHT 30

Food::Food(){
    srand(time(NULL));
    genFood();
}

void Food::genFood(){
    foodPos.x = rand() % WIDTH + 1; // 1 - width
    foodPos.y = rand() % HEIGHT + 1; // 1 - height
}

COORD2 Food::getFood(){
    return foodPos;
}