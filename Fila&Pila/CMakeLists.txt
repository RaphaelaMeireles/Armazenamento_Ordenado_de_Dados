cmake_minimum_required(VERSION 3.25)
project(Fila&Pilha)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(FilaePilha
        Fila.cpp
        Fila.h
	Pilha.cpp
	Pilha.h
        main.cpp)
