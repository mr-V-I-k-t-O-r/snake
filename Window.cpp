#ifndef WINDOW
#define WINDOW

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Snake.cpp"
#include "Apple.cpp"


class Window{
private:
    GLFWwindow* w;
    Snake snake;
    Apple apple;
public:
    Window(){
    }

    void start(){
        while(!glfwWindowShouldClose(w)){
            glfwSwapBuffers(w);
        }
    }

    bool getAlive(){
        return glfwWindowShouldClose(w);
    }

    void addSnake(Snake& s){
        snake = s;
    }

    void addApple(Apple& a){
        apple = a;
    }
};
#endif