#ifndef WINDOW
#define WINDOW

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Snake.cpp"
#include "Apple.cpp"

void framebufferSizeCallback(GLFWwindow* window, int width, int height);

class Window{
private:
    GLFWwindow* w;
    Snake snake;
    Apple apple;

    int height;
    int width;

    bool alive;

public:
    Window() = default;

    Window(int wi, int he){
        width = wi;
        height = he;

        alive = true;

        w = glfwCreateWindow(width, height, "Snake game", 0, 0);
        
    }

    void start(){
        glfwMakeContextCurrent(w);
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

        glfwSetFramebufferSizeCallback(w, framebufferSizeCallback);

        glViewport(0, 0, width, height);

        while(!glfwWindowShouldClose(w)){
            processInput(w);
            glfwPollEvents();    
            glClearColor(.2f, .8f, .3f, 1.f);
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(w);
        }
        alive = false;
        glfwTerminate();
    }

    bool getAlive(){
        if(alive){
            return !glfwWindowShouldClose(w);
        }
        return false;
    }

    void addSnake(Snake& s){
        snake = s;
    }

    void addApple(Apple& a){
        apple = a;
    }

    void processInput(GLFWwindow *window){
      if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
      }
      if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS){
        snake.setDirection("up");
      }
      if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS){
        snake.setDirection("down");
      }
      if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS){
        snake.setDirection("left");
      }
      if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS){
        snake.setDirection("right");
      }
    }
};

void framebufferSizeCallback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

#endif