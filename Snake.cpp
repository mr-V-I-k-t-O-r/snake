#ifndef SNAKE
#define SNAKE
class Snake{
private:
    bool alive;

    int height;
    int width;

    int headRow;
    int headCol;

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
};
#endif