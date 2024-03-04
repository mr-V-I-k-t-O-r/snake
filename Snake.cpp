#include "Snake.h"
#include <iostream>
#include <time.h>
#include <random>

Field::Field()
{
    this->x = 0;
    this->y = 0;
    this->field = nullptr;
}

Field::Field(const int&X, const int& Y)
{
    this->x = X;
    this->y = Y;
    this->field = new char*[Y];
    for(int i = 0; i < Y; ++i)
    {
        this->field[i] = new char[X];
        for(int j = 0; j < X; ++j)
        this->field[i][j] = ' ';
    }
}

Field::~Field()
{
    for(int i = 0; i < this->y; ++i)
        delete[] this->field[i];
    delete[] this->field;
}

void Field::print()
{
    for(int i = 0; i < this->y; ++i)
    {
        for(int j = 0; j < this->x; ++j)
            std::cout << this->field[i][j];
        std::cout << '\n';
    }
}

void Field::place(const int& X, const int& Y, const char& sign)
{
    this->field[Y][X] = sign;
}


void Apple::chpos(const int& X, const int& Y)
{
    srand(time(0));
    this->x = rand() % (X - 2) + 1;
    this->y = rand() % (Y - 2) + 1;
}

void Apple::print(Field& field)
{
    field.place(this->x, this->y, '0');
}

Element::Element(const int& X, const int& Y, Element* last)
{
    this->x = X;
    this->y = Y;
    this->next = last;
}

Element::Element(const int& X, const int& Y)
{
    this->x = X;
    this->y = Y;
}

const int& Element::get_x()
{
    return this->x;
}

const int& Element::get_y()
{
    return this->y;
}

void Element::mov()
{
    this->x = this->next->get_x();
    this->y = this->next->get_y();
}

void Element::mov(const char& dir)
{
    if(dir == 't')
        {
            --y;
        }
    else if (dir == 'l')
        {
            --x;
        }
    else if (dir == 'r')
        {
            ++x;
        }
    else if (dir == 'b')
        {
            ++y;
        }
}

void Element::print(Field& field)
{
    field.place(this->x, this->y, '@');
}

Element* Element::get_next()
{
    return this->next;
}


Snake::Snake(const int& X, const int& Y)
{
    this->head = new Element(X / 2, Y / 2);
    this->tail = head;
    this->alive = true;
}

Snake::~Snake()
{
    Element* now = this->tail;
    Element* del = this->tail->get_next();
    while(now != this->head)
    {
        delete now;
        now = del;
        del = del->get_next();
    }
    now = nullptr;
    del = nullptr;
    delete this->head;

}

void Snake::mov(const char& dir)
{
    Element* now = this->tail;
    while(now != this->head)
    {
        now->mov();
        now = now->get_next();
    }
    this->head->mov(dir);
}

void Snake::grow()
{
    Element* n = new Element(tail->get_x(), tail->get_y(), tail);
    tail = n;
    n = nullptr;
}

void Snake::death()
{
    this->alive = false;
}

void Snake::print(Field& field)
{
    Element* now = this->tail;
    while(now != this->head)
    {
        now->print(field);
        now->get_next();
    }
    now->print(field);
}

