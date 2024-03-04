#ifndef SNAKE_H
#define SNAKE_H

class Apple
{
    public:
        void chpos(const int& X, const int&Y);

    private:
        int x;
        int y;

};

class Element
{
    public:
        Element(const int& X, const int& Y,Element* last);
        Element(const int& X, const int& Y);
        void mov();
        void mov(const char& dir);
        const int& get_x() ;
        const int& get_y();
        Element* get_next();

    private:
        int x;
        int y;
        Element* next;
};

class Snake
{
    public:
        Snake(const int& X, const int& Y);
        ~Snake();
        void grow();
        void mov(const char& dir);
        void death();

    private:
        Element* head;
        Element* tail;
        bool alive;
};

#endif // SNAKE_H
