#ifndef SNAKE_H
#define SNAKE_H

class Field
{
    public:
        Field();
        Field(const int& X, const int& Y);
        ~Field();
        void print();
        void place(const int& X, const int& Y, const char& sign);


    private:
        int x;
        int y;
        char** field;

};



class Apple
{
    public:
        void chpos(const int& X, const int&Y);
        void print(Field& field);

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
        void print(Field& field);
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
        void print(Field& field);

    private:
        Element* head;
        Element* tail;
        bool alive;
};

#endif // SNAKE_H
