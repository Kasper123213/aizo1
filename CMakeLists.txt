cmake_minimum_required(VERSION 3.28)
project(aizo1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(aizo1 src/main.cpp src/tests/AutoTest.h src/tests/AutoTest.cpp src/tests/ManualTest.h src/tests/ManualTest.cpp src/time/Czas.h src/time/Czas.cpp src/structures/Table.h src/structures/Table.cpp src/sortingAlgorithms/QuickSort.cpp src/sortingAlgorithms/QuickSort.h src/sortingAlgorithms/QuickSort.cpp src/sortingAlgorithms/HeapSort.h src/sortingAlgorithms/HeapSort.cpp src/structures/Heap.h src/structures/Heap.cpp src/sortingAlgorithms/InsertionSort.h src/sortingAlgorithms/InsertionSort.cpp src/sortingAlgorithms/BinaryInsertionSort.h src/sortingAlgorithms/BinaryInsertionSort.cpp)
