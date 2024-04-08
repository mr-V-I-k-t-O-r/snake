#ifndef SNAKE_H
#define SNAKE_H

class Field
{
    public:
        Field();
        Field(const unsigned int& X, const unsigned int& Y);
        ~Field();
        void print();
        void place(const unsigned int& X, const unsigned int& Y, const char& sign);
        void update();
        const char& get_sign(const unsigned int& X, const unsigned int& Y);

    private:
        unsigned int x;
        unsigned int y;
        char** field;

};


class Apple
{
    public:
        void chpos(const unsigned int& X, const unsigned int&Y);
        void print(Field& field);

    private:
        unsigned int x;
        unsigned int y;

};


class Element
{
    public:
        Element(const unsigned int& X, const unsigned int& Y, Element* last);
        Element(const unsigned int& X, const unsigned int& Y);
        void mov();
        void mov(const char& dir);
        void print(Field& field);
        const unsigned int& get_x();
        const unsigned int& get_y();
        Element* get_next();

    private:
        unsigned int x;
        unsigned int y;
        Element* next;
};


class Snake
{
    public:
        Snake(const unsigned int& X, const unsigned int& Y);
        ~Snake();
        void grow();
        void mov(const char& dir);
        void death();
        void print(Field& field);
        bool alive();
        const int& get_x_head();
        const int& get_y_head();

    private:
        Element* head;
        Element* tail;
        bool live;
};


class Game
{
    public:
        Game(const unsigned int& X, const unsigned int& Y);
        ~Game();
        void start();
    private:
        Snake* snake;
        Apple* apple;
        Field* field;
        char dir;
        int x;
        int y;
};

#endif // SNAKE_H
