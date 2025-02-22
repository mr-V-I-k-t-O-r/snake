#ifndef SNAKE
#define SNAKE
class Snake{
private:
    bool alive;

    int maxRow;
    int maxCol;

    int headRow;
    int headCol;
public:
    bool getAlive(){
        return alive;
    }

    Snake() = default;

    Snake(int mC, int mR){
        maxCol = mC;
        maxRow = mR;

        headRow = maxRow / 2;
        headCol = maxCol / 2;
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