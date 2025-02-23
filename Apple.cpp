#ifndef APPLE
#define APPLE

#include <random>
#include <ctime>
 
class Apple{
private:
    int height;
    int width;

    int row;
    int col;
    
public:
    Apple() = default;

    Apple(int wi, int he){
        width = wi;
        height = he;
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