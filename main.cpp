#include <thread>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Apple.cpp"
#include "Snake.cpp"
#include "Window.cpp"

int main(){

    glfwInit();

    Window w;
    Snake s;
    Apple a;
    w.addSnake(s);
    w.addApple(a);
    
    std::thread windowThr(&Window::start, &w);
    windowThr.detach();

    while(s.getAlive() and w.getAlive()){

    }
    return 0;
}