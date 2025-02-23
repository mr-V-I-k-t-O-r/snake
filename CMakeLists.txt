cmake_minimum_required(VERSION 3.10)

project(main)

set(SOURCES
    main.cpp
    Apple.cpp
    Snake.cpp
    Window.cpp
)

add_executable(main ${SOURCES})

target_link_libraries(main
    GL
    glad
    glfw
)