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

    int height;
    int width;

public:
    Window() = default;

    Window(int wi, int he){
        width = wi;
        height = he;

        w = glfwCreateWindow(width, height, "Snake game", 0, 0);
        glfwMakeContextCurrent(w);
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

        glViewport(0, 0, width, height);
    }

    void start(){
        while(!glfwWindowShouldClose(w)){

            glfwPollEvents();    
            glClearColor(.5f, .5f, .5f, 1.f);
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(w);

        }
        glfwTerminate();
    }

    bool getAlive(){
        return !glfwWindowShouldClose(w);
    }

    void addSnake(Snake& s){
        snake = s;
    }

    void addApple(Apple& a){
        apple = a;
    }
};
#endif