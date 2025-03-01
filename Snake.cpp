#ifndef SNAKE
#define SNAKE

#include <string>

class Snake{
private:
    bool alive;

    int height;
    int width;

    int headRow;
    int headCol;

    std::string direction;

public:
    bool getAlive(){
        return alive;
    }

    Snake() = default;

    Snake(int wi, int he){
        width = wi;
        height = he;

        headRow = height / 2;
        headCol = width / 2;
        alive = true;
    }

    int getHeadRow(){
        return headRow;
    }

    int getHeadCol(){
        return headCol;
    }

    void setDirection(std::string dir){
        direction = dir;
    }
};
#endif