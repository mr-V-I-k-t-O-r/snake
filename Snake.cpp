#ifndef SNAKE
#define SNAKE
class Snake{
private:
    bool alive;
public:
    bool getAlive(){
        return alive;
    }

    Snake(){
        alive = true;
    }
};
#endif