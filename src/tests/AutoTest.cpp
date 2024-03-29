
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

//30 50 70 90 110 130 150 tys
AutoTest::AutoTest() {

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


//todo zmienic testy z 20 na 100






//###########################               int
    runTest<int>();

//###########################               float
    runTest<float>();
}




AutoTest::~AutoTest() {

}

template<typename T>
void AutoTest::runTest() {
    Time* time = new Time();
    long sortingTime;
    int minSize = 30000;
    int maxSize = 150000;
    int step = 20000;

    //long* times = new long[100];

    Table<T>* table = new Table<T>;
    Table<T>* sortedTable = new Table<T>;


//InsertSort

    InsertionSort<T>* insertionSort = new InsertionSort<T>(table);

    string name = "insertionSort" + string(typeid(T).name()) + ".csv";
    ofstream file(name, ios::app);

    cout<<"################################"<<name<<endl;
    //todo fullrandom
    cout<<"###################### fullrandom"<<endl;
    for(int size=minSize; size<=maxSize; size+=step) {
        cout<<"################size: "<<size<<endl;
        for(int i=0; i<100; i++) {
            cout<<i<<endl;
            table->randomFULL(size);
            insertionSort->setNewTable(table);

            time->start();
            sortedTable = insertionSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime<<";";
        }
        file << endl;
    }

    //todo malejacy random
    cout<<"###################### maleje"<<endl;
    for(int size=minSize; size<=maxSize; size+=step) {
        cout<<"################size: "<<size<<endl;
        for(int i=0; i<100; i++) {
            cout<<i<<endl;
            table->randomDescending(size);
            insertionSort->setNewTable(table);

            time->start();
            sortedTable = insertionSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime<<";";
        }
        file << endl;
    }

    //todo sorted100
    cout<<"###################### 100rand"<<endl;
    for(int size=minSize; size<=maxSize; size+=step) {
        cout<<"################size: "<<size<<endl;
        for(int i=0; i<100; i++) {
            cout<<i<<endl;
            table->randomPercent(size, 100);
            insertionSort->setNewTable(table);

            time->start();
            sortedTable = insertionSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime<<";";
        }
        file << endl;
    }

    //todo sorted 66
    cout<<"###################### 66 rand"<<endl;
    for(int size=minSize; size<=maxSize; size+=step) {
        cout<<"################size: "<<size<<endl;
        for(int i=0; i<100; i++) {
            cout<<i<<endl;
            table->randomPercent(size, 66);
            insertionSort->setNewTable(table);

            time->start();
            sortedTable = insertionSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime<<";";
        }
        file << endl;
    }

    //todo sorted 33
    cout<<"###################### 33 rand"<<endl;
    for(int size=minSize; size<=maxSize; size+=step) {
        cout<<"################size: "<<size<<endl;
        for(int i=0; i<100; i++) {
            cout<<i<<endl;
            table->randomPercent(size, 33);
            insertionSort->setNewTable(table);

            time->start();
            sortedTable = insertionSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime<<";";
        }
        file << endl;
    }



    file.close();
    delete insertionSort;






//binary insert

    BinaryInsertionSort<T>* binaryInsertionSort = new BinaryInsertionSort<T>(table);

    name = "binaryInsertionSort" + string(typeid(T).name()) + ".csv";
    file.open(name, ios::app);

    cout<<"################################"<<name<<endl;
    //todo fullrandom
    cout<<"###################### fullrandom"<<endl;
    for(int size=minSize; size<=maxSize; size+=step) {
        cout<<"################size: "<<size<<endl;
        for(int i=0; i<100; i++) {
            cout<<i<<endl;
            table->randomFULL(size);
            binaryInsertionSort->setNewTable(table);

            time->start();
            sortedTable = binaryInsertionSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime<<";";
        }
        file << endl;
    }

    //todo malejacy random
    cout<<"###################### maleje"<<endl;
    for(int size=minSize; size<=maxSize; size+=step) {
        cout<<"################size: "<<size<<endl;
        for(int i=0; i<100; i++) {
            cout<<i<<endl;
            table->randomDescending(size);
            binaryInsertionSort->setNewTable(table);

            time->start();
            sortedTable = binaryInsertionSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime<<";";
        }
        file << endl;
    }

    //todo sorted100
    cout<<"###################### 100rand"<<endl;
    for(int size=minSize; size<=maxSize; size+=step) {
        cout<<"################size: "<<size<<endl;
        for(int i=0; i<100; i++) {
            cout<<i<<endl;
            table->randomPercent(size, 100);
            binaryInsertionSort->setNewTable(table);

            time->start();
            sortedTable = binaryInsertionSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime<<";";
        }
        file << endl;
    }

    //todo sorted 66
    cout<<"###################### 66 rand"<<endl;
    for(int size=minSize; size<=maxSize; size+=step) {
        cout<<"################size: "<<size<<endl;
        for(int i=0; i<100; i++) {
            cout<<i<<endl;
            table->randomPercent(size, 66);
            binaryInsertionSort->setNewTable(table);

            time->start();
            sortedTable = binaryInsertionSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime<<";";
        }
        file << endl;
    }

    //todo sorted 33
    cout<<"###################### 33 rand"<<endl;
    for(int size=minSize; size<=maxSize; size+=step) {
        cout<<"################size: "<<size<<endl;
        for(int i=0; i<100; i++) {
            cout<<i<<endl;
            table->randomPercent(size, 33);
            binaryInsertionSort->setNewTable(table);

            time->start();
            sortedTable = binaryInsertionSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime<<";";
        }
        file << endl;
    }



    file.close();
    delete binaryInsertionSort;
















//heapsort


    HeapSort<T>* heapSort = new HeapSort<T>(table);

    name = "heapSort" + string(typeid(T).name()) + ".csv";
    file.open(name, ios::app);

    cout<<"################################"<<name<<endl;
    //todo fullrandom
    cout<<"###################### fullrandom"<<endl;
    for(int size=minSize; size<=maxSize; size+=step) {
        cout<<"################size: "<<size<<endl;
        for(int i=0; i<100; i++) {
            cout<<i<<endl;
            table->randomFULL(size);
            heapSort->setNewTable(table);

            time->start();
            sortedTable = heapSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime<<";";
        }
        file << endl;
    }

    //todo malejacy random
    cout<<"###################### maleje"<<endl;
    for(int size=minSize; size<=maxSize; size+=step) {
        cout<<"################size: "<<size<<endl;
        for(int i=0; i<100; i++) {
            cout<<i<<endl;
            table->randomDescending(size);
            heapSort->setNewTable(table);

            time->start();
            sortedTable = heapSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime<<";";
        }
        file << endl;
    }

    //todo sorted100
    cout<<"###################### 100rand"<<endl;
    for(int size=minSize; size<=maxSize; size+=step) {
        cout<<"################size: "<<size<<endl;
        for(int i=0; i<100; i++) {
            cout<<i<<endl;
            table->randomPercent(size, 100);
            heapSort->setNewTable(table);

            time->start();
            sortedTable = heapSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime<<";";
        }
        file << endl;
    }

    //todo sorted 66
    cout<<"###################### 66 rand"<<endl;
    for(int size=minSize; size<=maxSize; size+=step) {
        cout<<"################size: "<<size<<endl;
        for(int i=0; i<100; i++) {
            cout<<i<<endl;
            table->randomPercent(size, 66);
            heapSort->setNewTable(table);

            time->start();
            sortedTable = heapSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime<<";";
        }
        file << endl;
    }

    //todo sorted 33
    cout<<"###################### 33 rand"<<endl;
    for(int size=minSize; size<=maxSize; size+=step) {
        cout<<"################size: "<<size<<endl;
        for(int i=0; i<100; i++) {
            cout<<i<<endl;
            table->randomPercent(size, 33);
            heapSort->setNewTable(table);

            time->start();
            sortedTable = heapSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime<<";";
        }
        file << endl;
    }



    file.close();
    delete heapSort;
















//qs


    QuickSort<T>* quickSort = new QuickSort<T>(table);

    name = "quickSort" + string(typeid(T).name()) + ".csv";
    file.open(name, ios::app);

    cout<<"################################"<<name<<endl;
    //todo fullrandom
    cout<<"###################### fullrandom"<<endl;
    for(int size=minSize; size<=maxSize; size+=step) {
        cout<<"################size: "<<size<<endl;
        for(int i=0; i<100; i++) {
            cout<<i<<endl;
            table->randomFULL(size);
            quickSort->setNewTable(table);

            time->start();
            sortedTable = quickSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime<<";";
        }
        file << endl;
    }

    //todo malejacy random
    cout<<"###################### maleje"<<endl;
    for(int size=minSize; size<=maxSize; size+=step) {
        cout<<"################size: "<<size<<endl;
        for(int i=0; i<100; i++) {
            cout<<i<<endl;
            table->randomDescending(size);
            quickSort->setNewTable(table);

            time->start();
            sortedTable = quickSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime<<";";
        }
        file << endl;
    }

    //todo sorted100
    cout<<"###################### 100rand"<<endl;
    for(int size=minSize; size<=maxSize; size+=step) {
        cout<<"################size: "<<size<<endl;
        for(int i=0; i<100; i++) {
            cout<<i<<endl;
            table->randomPercent(size, 100);
            quickSort->setNewTable(table);

            time->start();
            sortedTable = quickSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime<<";";
        }
        file << endl;
    }

    //todo sorted 66
    cout<<"###################### 66 rand"<<endl;
    for(int size=minSize; size<=maxSize; size+=step) {
        cout<<"################size: "<<size<<endl;
        for(int i=0; i<100; i++) {
            cout<<i<<endl;
            table->randomPercent(size, 66);
            quickSort->setNewTable(table);

            time->start();
            sortedTable = quickSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime<<";";
        }
        file << endl;
    }

    //todo sorted 33
    cout<<"###################### 33 rand"<<endl;
    for(int size=minSize; size<=maxSize; size+=step) {
        cout<<"################size: "<<size<<endl;
        for(int i=0; i<100; i++) {
            cout<<i<<endl;
            table->randomPercent(size, 33);
            quickSort->setNewTable(table);

            time->start();
            sortedTable = quickSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime<<";";
        }
        file << endl;
    }



    file.close();
    delete quickSort;






    delete table;
    delete sortedTable;
}

