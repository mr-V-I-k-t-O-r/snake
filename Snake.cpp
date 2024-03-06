#include "Snake.h"
#include <iostream>
#include <time.h>
#include <random>
#include <curses.h>

Field::Field()
{
    this->x = 0;
    this->y = 0;
    this->field = nullptr;
}

Field::Field(const unsigned int&X, const unsigned int& Y)
{
    this->x = X;
    this->y = Y;
    this->field = new char*[Y];
    for(int i = 0; i < Y; ++i)
    {
        this->field[i] = new char[X];
    }
}

Field::~Field()
{
    for(unsigned int i = 0; i < this->y; ++i)
        delete[] this->field[i];
    delete[] this->field;
}

void Field::print()
{
    for(unsigned int i = 0; i < this->y; ++i)
    {
        for(unsigned int j = 0; j < this->x; ++j)
            std::cout << this->field[i][j];
        std::cout << '\n';
    }
}

void Field::place(const unsigned int& X, const unsigned int& Y, const char& sign)
{
    this->field[Y][X] = sign;
}

void Field::update()
{
    for(int i = 0; i < this->y; ++i)
    {
        for(int j = 0; j < this->x; ++j)
        {
            if(i == 0 || j == 0 || i == this->y - 1 || j == this->x - 1)
            {
                this->field[i][j] = '#';
            }
            else
            {
                this->field[i][j] = ' ';
            }
        }
    }
}

const char& Field::get_sign(const unsigned int& X, const unsigned int& Y)
{
    return this->field[Y][X];
}


void Apple::chpos(const unsigned int& X, const unsigned int& Y)
{
    srand(time(0));
    this->x = rand() % (X - 2) + 1;
    this->y = rand() % (Y - 2) + 1;
}

void Apple::print(Field& field)
{
    field.place(this->x, this->y, '0');
}

Element::Element(const unsigned int& X, const unsigned int& Y, Element* last)
{
    this->x = X;
    this->y = Y;
    this->next = last;
}

Element::Element(const unsigned int& X, const unsigned int& Y)
{
    this->x = X;
    this->y = Y;
}

const unsigned int& Element::get_x()
{
    return this->x;
}

const unsigned int& Element::get_y()
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


Snake::Snake(const unsigned int& X, const unsigned int& Y)
{
    this->head = new Element(X / 2, Y / 2);
    this->tail = head;
    this->live = true;
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
    this->live = false;
}

void Snake::print(Field& field)
{
    Element* now = this->tail;
    while(now != this->head)
    {
        now->print(field);
        now = now->get_next();
    }
    now->print(field);
}

bool Snake::alive()
{
    return this->live;
}

const int& Snake::get_x_head()
{
    return this->head->get_x();
}

const int& Snake::get_y_head()
{
    return this->head->get_y();
}


Game::Game(const unsigned int& X, const unsigned int& Y)
{
    this->field = new Field(X, Y);
    this->snake = new Snake(X, Y);
    this->apple = new Apple();
    this->x = X;
    this->y = Y;
}

Game::~Game()
{
    delete this->field;
    this->field = nullptr;

    delete this->snake;
    this->snake = nullptr;

    delete this->apple;
    this->apple = nullptr;
}

void Game::start()
{
    this->apple->chpos(this->x, this->y);
    this->field->update();
    while(this->snake->alive())
    {
        std::cin >> dir;
        this->snake->mov(dir);
        system("clear");

        char head_position = this->field->get_sign(this->snake->get_x_head(), this->snake->get_y_head());

        this->field->update();
        this->apple->print(*this->field);

        if(head_position == '0')
        {
            this->snake->grow();
            this->apple->chpos(this->x, this->y);
        }
        else if(head_position != ' ')
        {
            this->snake->death();
        }

        this->snake->print(*this->field);
        this->field->print();
    }
}




