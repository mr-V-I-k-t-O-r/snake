#ifndef SNAKE_H
#define SNAKE_H

class Element
{
    public:
        Element(const int& X, const int& Y,Element* last);
        Element(const int& X, const int& Y);
        void mov();
        void mov(const char& dir);
        const int& get_x() ;
        const int& get_y();

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
