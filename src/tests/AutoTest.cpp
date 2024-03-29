
#include <fstream>
#include <iostream>
#include "AutoTest.h"
#include "../structures/Table.h"
#include "../sortingAlgorithms/InsertionSort.h"
#include "../sortingAlgorithms/BinaryInsertionSort.h"
#include "../sortingAlgorithms/HeapSort.h"
#include "../sortingAlgorithms/QuickSort.h"
#include "../time/Time.h"

//100 instancji 7 rozmiarów
//pesymistycznie dla n = 300000 czas to 360 s przy insertion sort
//pesymistycznie dla n = 300000 czas to 150 s przy insertion sort binarmie
//pesymistycznie dla n = 300000 czas to 126 s przy kopcowaniu
//pesymistycznie dla n = 300000 czas to 0.031 s przy szybkim
//pesymistycznie dla n = 1000`000`000 czas to 160 s przy quick sort

//qs 25000 0.001s
//is 175000 105s
//todo usunąć wszędzie unsigned long long
//30 50 70 90 110 130 150
AutoTest::AutoTest() {
    Time* time;
    string name ;

//100 instancji
//7 rozmiarow
//4 algorytmy
//3 typy danych
//5 rozkladow danych

//plik zawiera:

//  int                                         |long
//  rozklad danych              |rozklad rosnący|
//  rozmiar1    |rozmiar2|...   |...            |
//  100|100|100 |         ...   |               |


//testowanie quicksort dla int rozmiar 300 000 rozklad losowy









//###########################               int
    runTest<int>();

//###########################               float
    runTest<float>();
}




AutoTest::~AutoTest() {

}

template<typename T>
void AutoTest::runTest() {



    Table<T>* table = new Table<T>;
    Table<T>* sortedTable = new Table<T>;

//InsertSort
    InsertionSort<T>* insertionSort = new InsertionSort(table);

    //todo fullrandom
    table->randomFULL(5);
    insertionSort->setNewTable(table);

    sortedTable = insertionSort->sort();

    cout<<endl<<endl<<endl;
    table->printTable();
    sortedTable->printTable();

    if(not sortedTable->isSorted()) {
        std::cout<<"Sortowanie nie powiodło się"<<std::endl;
        return;
    }

    //todo malejacy random
    table->randomDescending(5);
    insertionSort->setNewTable(table);

    sortedTable = insertionSort->sort();

    cout<<endl<<endl<<endl;
    table->printTable();
    sortedTable->printTable();

    if(not sortedTable->isSorted()) {
        std::cout<<"Sortowanie nie powiodło się"<<std::endl;
        return;
    }


    //todo sorted100
    table->randomPercent(5, 100);
    insertionSort->setNewTable(table);

    sortedTable = insertionSort->sort();

    cout<<endl<<endl<<endl;
    table->printTable();
    sortedTable->printTable();

    if(not sortedTable->isSorted()) {
        std::cout<<"Sortowanie nie powiodło się"<<std::endl;
        return;
    }

    //todo sorted 66
    table->randomPercent(5, 66);
    insertionSort->setNewTable(table);

    sortedTable = insertionSort->sort();

    cout<<endl<<endl<<endl;
    table->printTable();
    sortedTable->printTable();

    if(not sortedTable->isSorted()) {
        std::cout<<"Sortowanie nie powiodło się"<<std::endl;
        return;
    }

    //todo sorted 33
    table->randomPercent(5, 33);
    insertionSort->setNewTable(table);

    sortedTable = insertionSort->sort();

    cout<<endl<<endl<<endl;
    table->printTable();
    sortedTable->printTable();

    if(not sortedTable->isSorted()) {
        std::cout<<"Sortowanie nie powiodło się"<<std::endl;
        return;
    }




    delete insertionSort;

//binary insert

    //todo fullrandom

    //todo malejacy random

    //todo sorted100

    //todo sorted 66

    //todo sorted 33


//heapsort

    //todo fullrandom

    //todo malejacy random

    //todo sorted100

    //todo sorted 66

    //todo sorted 33


//qs

    //todo fullrandom

    //todo malejacy random

    //todo sorted100

    //todo sorted 66

    //todo sorted 33






    delete table;
    delete sortedTable;
}

