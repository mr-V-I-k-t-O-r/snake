#ifndef APPLE
#define APPLE

#include <random>
#include <ctime>
 
class Apple{
private:
    int maxRow;
    int maxCol;

    int row;
    int col;
    
public:
    Apple() = default;

    Apple(int mC, int mR){
        maxCol = mC;
        maxRow = mR;
        srand(time(0));
        changePos();
    }

    void changePos(){
        row = rand();
        col = rand();
    }

    int getRow(){
        return row;
    }

    int getCol(){
        return col;
    }
};
#endif