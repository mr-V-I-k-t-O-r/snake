#include "Snake.h"
#include <iostream>

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
    this->x = next->get_x();
    this->y = next->get_y();
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

Snake::Snake(const int& X, const int& Y)
{
    this->head = new Element(X / 2, Y / 2);
    this->tail = head;
    this->alive = true;
}

Snake::~Snake()
{

}

void Snake::mov(const char& dir)
{
    this->head->mov();
}
