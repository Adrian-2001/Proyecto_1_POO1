cmake_minimum_required(VERSION 3.14)
project(Borrador_punteros)

set(CMAKE_CXX_STANDARD 17)

add_executable(Borrador main.cpp Tipos.h CObjeto.cpp CObjeto.h CArena.cpp CArena.h CMenu.cpp CMenu.h CRobot.cpp CRobot.h CObstaculo.cpp CObstaculo.h)