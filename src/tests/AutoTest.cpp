
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



//InsertSort

    //int
        //todo fullrandom
    Table<int>* table = new Table<int>;
    Table<int>* sortedTable = new Table<int>;
    InsertionSort<int>* insertionSort = new InsertionSort(table);
    table->randomFULL(5);
    insertionSort->setNewTable(table);

    sortedTable = insertionSort->sort();

    sortedTable->printTable();
    if(sortedTable->isSorted()) {
        std::cout<<"zrobione"<<std::endl;
        delete insertionSort;
        delete table;
        delete sortedTable;
    }
    else{
        std::cout<<"zepsulo sie"<<std::endl;
        delete insertionSort;
        delete table;
        delete sortedTable;
        return;
    }
        //todo malejacy random

        //todo sorted100

        //todo sorted 66

        //todo sorted 33

    //float
        //todo fullrandom

        //todo malejacy random

        //todo sorted100

        //todo sorted 66

        //todo sorted 33

//binary insert
    //int
        //todo fullrandom

        //todo malejacy random

        //todo sorted100

        //todo sorted 66

        //todo sorted 33

    //float
        //todo fullrandom

        //todo malejacy random

        //todo sorted100

        //todo sorted 66

        //todo sorted 33

//heapsort
    //int
        //todo fullrandom

        //todo malejacy random

        //todo sorted100

        //todo sorted 66

        //todo sorted 33

    //float
        //todo fullrandom

        //todo malejacy random

        //todo sorted100

        //todo sorted 66

        //todo sorted 33

//qs
    //int
        //todo fullrandom

        //todo malejacy random

        //todo sorted100

        //todo sorted 66

        //todo sorted 33

    //float
        //todo fullrandom

        //todo malejacy random

        //todo sorted100

        //todo sorted 66

        //todo sorted 33


}

AutoTest::~AutoTest() {

}
