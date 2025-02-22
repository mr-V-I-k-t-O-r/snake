cmake_minimum_required(VERSION 3.10)

project(SnakeGame)

set(SOURCES
    main.cpp
    Apple.cpp
    Snake.cpp
    Window.cpp
)

add_executable(make ${SOURCES})

target_link_libraries(make
    GL
    glad
    glfw
)