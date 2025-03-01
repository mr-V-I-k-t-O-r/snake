#include <thread>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <unistd.h>

#include "Apple.cpp"
#include "Snake.cpp"
#include "Window.cpp"

int main(){

    const int WIDTH = 600;
    const int HEIGTH = 600;

    glfwInit();

    Window w(WIDTH, HEIGTH);
    Snake s(WIDTH, HEIGTH);
    Apple a(WIDTH, HEIGTH);
    w.addSnake(s);
    w.addApple(a);

    std::cout << "call window start\n";
    
    std::thread windowThr(&Window::start, &w);
    windowThr.detach();
    sleep(3);

    while(s.getAlive() and w.getAlive()){
        ;
    }
    return 0;
}