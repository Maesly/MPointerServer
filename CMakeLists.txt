cmake_minimum_required(VERSION 3.12)
project(MPointerServer)

set(CMAKE_CXX_STANDARD 14)

add_executable(MPointerServer main.cpp Servidor/Server.cpp Servidor/Server.h Servidor/Lista_Enlazada_Simple.cpp Servidor/Lista_Enlazada_Simple.h Servidor/Nodo_Simple.h)