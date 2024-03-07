cmake_minimum_required(VERSION 3.28)
project(aizo1)

set(CMAKE_CXX_STANDARD 17)

add_executable(aizo1 src/main.cpp src/testy/TestyAutomatyczne.h src/testy/TestyAutomatyczne.cpp src/testy/TestyManualne.h src/testy/TestyManualne.cpp src/czas/Czas.h src/czas/Czas.cpp)
