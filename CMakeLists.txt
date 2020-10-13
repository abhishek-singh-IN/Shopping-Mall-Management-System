cmake_minimum_required(VERSION 3.17)
project(Shopping_Mall_Management_System)

set(CMAKE_CXX_STANDARD 20)

add_executable(Shopping_Mall_Management_System main.cpp src/menu.cpp src/menu.h src/item.cpp src/item.h src/account.cpp src/account.h)