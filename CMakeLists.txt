cmake_minimum_required(VERSION 3.0)

project (snake)

set(SOURCE_EXE main.cpp Snake.cpp Window.cpp Apple.cpp)

add_executable(main ${SOURCE_EXE})

add_compile_options(-L /usr/include/glad -lGL -lglw -lGLEW -lGLU -lglad)
