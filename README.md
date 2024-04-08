# snake
this is a simple snake game, which i write for practice in C++.

this project need mostly for train in oop and some system functions

## functions

### Field

Field() - default constructor, without memory allocation

Field(X, Y) - constructor, which create field for game with width = X, height = Y

~Field() - destructor, where clears memory

print() - print field in console

place(X, Y, sign) - change field symbol on position (X:Y) on sign

update() - clear field from snake and apple

get_sign(X, Y) - return field symbol on position (X:Y)

### Apple

this class isn't allocate memory and has only 2 integer class field. This is a reason, why is hasn't constructor and destructor

chpos(X, Y) - change position of apple on the field with width = X, height = Y

print(field) - add apple to the field

### Element

Element(X, Y, last) - add new element of snake to the tail with pointer to old tail

Element(X, Y) - add new element of snake without pointer to next element

mov() - change position of this element of snake on position of next element of snake

mov(dir) - chande position of this element in someone direction, which you give

print(field) - add this element of snake to the field

get_x() - return value of X

get_y() - return value of Y

get_next() - return pointer to next element of snake

### Snake

Snake(X, Y) - snake constructor, which create head on the middle of the field which has width = X, height = Y

~Snake() - destructor which clears pointers to head and tail

grow() - create new element of snake and add it to the tail

mov(dir) - move every element of snake on the place of the next element and move head in direction

death() - makes class field which need to knew is snake alive to false

print(field) - add snake to the field

alive() - return value of a class field which need to knew is snake alive

get_x_head() - return value of X of a snake head

get_y_head() - return value of Y of a snake head

### Game

Game(X, Y) - constructor which create field, snake, apple 

~Game() - destructor which clear memory 

start() - start game and run game loop
