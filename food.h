#ifndef FOOD_H    // if not already defined is meaing
#define FOOD_H

struct COORD2{
    int x;
    int y;
};


class Food{
private:
    COORD2 foodPos;
public:
    Food();
    void genFood();
    COORD2 getFood();
    
};

#endif 