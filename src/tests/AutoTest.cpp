
#include <fstream>
#include <iostream>
#include "AutoTest.h"
#include "../structures/Table.h"
#include "../sortingAlgorithms/InsertionSort.h"
#include "../sortingAlgorithms/BinaryInsertionSort.h"
#include "../sortingAlgorithms/HeapSort.h"
#include "../sortingAlgorithms/QuickSort.h"
#include "../time/Time.h"

AutoTest::AutoTest() {

//###########################               int
    runTest<int>();

//###########################               float
    runTest<float>();
}


AutoTest::~AutoTest() {

}

template<typename T>
void AutoTest::runTest() {
    Time *time = new Time();
    long sortingTime;
    int minSize = 30000;
    int maxSize = 150000;
    int step = 20000;


    Table<T> *table = new Table<T>;
    Table<T> *sortedTable = new Table<T>;


//InsertSort
    //tworzenie klasy obsługującej dany algorytm
    InsertionSort<T> *insertionSort = new InsertionSort<T>(table);

    //tworzenie nazwy pliku odpowiadającej typowi algorytmu oraz typowi danych na jakich algorytm operuje
    string name = "insertionSort" + string(typeid(T).name()) + ".csv";
    ofstream file(name, ios::app);  //otwieranie pliku

    //informacja zwrotna pozwalająca widzieć przebieg testów
    cout << "################################" << name << endl;
    // fullrandom
    cout << "###################### fullrandom" << endl;
    for (int size = minSize; size <= maxSize; size += step) {  //dla danych rozmiarów tablicy wykonywane są testy
        cout << "################size: " << size << endl;
        for (int i = 0; i < 100; i++) {  //każdy test wykonywany jest po 100 razy
            cout << i << endl;
            table->randomFULL(size);    //wypełnianie tebali danymi określonego rozkładu
            insertionSort->setNewTable(table);  //ustawianie nowej tabeli

            time->start();  //uruchomienie stopera
            sortedTable = insertionSort->sort();    //wykonanie algorytmu
            sortingTime = time->getTime();  // zapisanie czasu wykonania algorytmu

            if (not sortedTable->isSorted()) {  //sprawdzenie czy sortowanie wykonało się poprawnie
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime << ";"; //zapis czasu do pliku csv
        }
        file << endl;
    }

    // malejacy random
    cout << "###################### maleje" << endl;
    for (int size = minSize; size <= maxSize; size += step) {
        cout << "################size: " << size << endl;
        for (int i = 0; i < 100; i++) {
            cout << i << endl;
            table->randomDescending(size);
            insertionSort->setNewTable(table);

            time->start();
            sortedTable = insertionSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime << ";";
        }
        file << endl;
    }

    // sorted100
    cout << "###################### 100rand" << endl;
    for (int size = minSize; size <= maxSize; size += step) {
        cout << "################size: " << size << endl;
        for (int i = 0; i < 100; i++) {
            cout << i << endl;
            table->randomPercent(size, 100);
            insertionSort->setNewTable(table);

            time->start();
            sortedTable = insertionSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime << ";";
        }
        file << endl;
    }

    // sorted 66
    cout << "###################### 66 rand" << endl;
    for (int size = minSize; size <= maxSize; size += step) {
        cout << "################size: " << size << endl;
        for (int i = 0; i < 100; i++) {
            cout << i << endl;
            table->randomPercent(size, 66);
            insertionSort->setNewTable(table);

            time->start();
            sortedTable = insertionSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime << ";";
        }
        file << endl;
    }

    // sorted 33
    cout << "###################### 33 rand" << endl;
    for (int size = minSize; size <= maxSize; size += step) {
        cout << "################size: " << size << endl;
        for (int i = 0; i < 100; i++) {
            cout << i << endl;
            table->randomPercent(size, 33);
            insertionSort->setNewTable(table);

            time->start();
            sortedTable = insertionSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime << ";";
        }
        file << endl;
    }


    file.close();
    delete insertionSort;






//binary insert

    BinaryInsertionSort<T> *binaryInsertionSort = new BinaryInsertionSort<T>(table);

    name = "binaryInsertionSort" + string(typeid(T).name()) + ".csv";
    file.open(name, ios::app);

    cout << "################################" << name << endl;
    // fullrandom
    cout << "###################### fullrandom" << endl;
    for (int size = minSize; size <= maxSize; size += step) {
        cout << "################size: " << size << endl;
        for (int i = 0; i < 100; i++) {
            cout << i << endl;
            table->randomFULL(size);
            binaryInsertionSort->setNewTable(table);

            time->start();
            sortedTable = binaryInsertionSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime << ";";
        }
        file << endl;
    }

    // malejacy random
    cout << "###################### maleje" << endl;
    for (int size = minSize; size <= maxSize; size += step) {
        cout << "################size: " << size << endl;
        for (int i = 0; i < 100; i++) {
            cout << i << endl;
            table->randomDescending(size);
            binaryInsertionSort->setNewTable(table);

            time->start();
            sortedTable = binaryInsertionSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime << ";";
        }
        file << endl;
    }

    // sorted100
    cout << "###################### 100rand" << endl;
    for (int size = minSize; size <= maxSize; size += step) {
        cout << "################size: " << size << endl;
        for (int i = 0; i < 100; i++) {
            cout << i << endl;
            table->randomPercent(size, 100);
            binaryInsertionSort->setNewTable(table);

            time->start();
            sortedTable = binaryInsertionSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime << ";";
        }
        file << endl;
    }

    // sorted 66
    cout << "###################### 66 rand" << endl;
    for (int size = minSize; size <= maxSize; size += step) {
        cout << "################size: " << size << endl;
        for (int i = 0; i < 100; i++) {
            cout << i << endl;
            table->randomPercent(size, 66);
            binaryInsertionSort->setNewTable(table);

            time->start();
            sortedTable = binaryInsertionSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime << ";";
        }
        file << endl;
    }

    // sorted 33
    cout << "###################### 33 rand" << endl;
    for (int size = minSize; size <= maxSize; size += step) {
        cout << "################size: " << size << endl;
        for (int i = 0; i < 100; i++) {
            cout << i << endl;
            table->randomPercent(size, 33);
            binaryInsertionSort->setNewTable(table);

            time->start();
            sortedTable = binaryInsertionSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime << ";";
        }
        file << endl;
    }


    file.close();
    delete binaryInsertionSort;
















//heapsort


    HeapSort<T> *heapSort = new HeapSort<T>(table);

    name = "heapSort" + string(typeid(T).name()) + ".csv";
    file.open(name, ios::app);

    cout << "################################" << name << endl;
    // fullrandom
    cout << "###################### fullrandom" << endl;
    for (int size = minSize; size <= maxSize; size += step) {
        cout << "################size: " << size << endl;
        for (int i = 0; i < 100; i++) {
            cout << i << endl;
            table->randomFULL(size);
            heapSort->setNewTable(table);

            time->start();
            sortedTable = heapSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime << ";";
        }
        file << endl;
    }

    // malejacy random
    cout << "###################### maleje" << endl;
    for (int size = minSize; size <= maxSize; size += step) {
        cout << "################size: " << size << endl;
        for (int i = 0; i < 100; i++) {
            cout << i << endl;
            table->randomDescending(size);
            heapSort->setNewTable(table);

            time->start();
            sortedTable = heapSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime << ";";
        }
        file << endl;
    }

    // sorted100
    cout << "###################### 100rand" << endl;
    for (int size = minSize; size <= maxSize; size += step) {
        cout << "################size: " << size << endl;
        for (int i = 0; i < 100; i++) {
            cout << i << endl;
            table->randomPercent(size, 100);
            heapSort->setNewTable(table);

            time->start();
            sortedTable = heapSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime << ";";
        }
        file << endl;
    }

    // sorted 66
    cout << "###################### 66 rand" << endl;
    for (int size = minSize; size <= maxSize; size += step) {
        cout << "################size: " << size << endl;
        for (int i = 0; i < 100; i++) {
            cout << i << endl;
            table->randomPercent(size, 66);
            heapSort->setNewTable(table);

            time->start();
            sortedTable = heapSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime << ";";
        }
        file << endl;
    }

    // sorted 33
    cout << "###################### 33 rand" << endl;
    for (int size = minSize; size <= maxSize; size += step) {
        cout << "################size: " << size << endl;
        for (int i = 0; i < 100; i++) {
            cout << i << endl;
            table->randomPercent(size, 33);
            heapSort->setNewTable(table);

            time->start();
            sortedTable = heapSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime << ";";
        }
        file << endl;
    }


    file.close();
    delete heapSort;
















//qs


    QuickSort<T> *quickSort = new QuickSort<T>(table);

    name = "quickSort" + string(typeid(T).name()) + ".csv";
    file.open(name, ios::app);

    cout << "################################" << name << endl;
    // fullrandom
    cout << "###################### fullrandom" << endl;
    for (int size = minSize; size <= maxSize; size += step) {
        cout << "################size: " << size << endl;
        for (int i = 0; i < 100; i++) {
            cout << i << endl;
            table->randomFULL(size);
            quickSort->setNewTable(table);

            time->start();
            sortedTable = quickSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime << ";";
        }
        file << endl;
    }

    // malejacy random
    cout << "###################### maleje" << endl;
    for (int size = minSize; size <= maxSize; size += step) {
        cout << "################size: " << size << endl;
        for (int i = 0; i < 100; i++) {
            cout << i << endl;
            table->randomDescending(size);
            quickSort->setNewTable(table);

            time->start();
            sortedTable = quickSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime << ";";
        }
        file << endl;
    }

    // sorted100
    cout << "###################### 100rand" << endl;
    for (int size = minSize; size <= maxSize; size += step) {
        cout << "################size: " << size << endl;
        for (int i = 0; i < 100; i++) {
            cout << i << endl;
            table->randomPercent(size, 100);
            quickSort->setNewTable(table);

            time->start();
            sortedTable = quickSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime << ";";
        }
        file << endl;
    }

    // sorted 66
    cout << "###################### 66 rand" << endl;
    for (int size = minSize; size <= maxSize; size += step) {
        cout << "################size: " << size << endl;
        for (int i = 0; i < 100; i++) {
            cout << i << endl;
            table->randomPercent(size, 66);
            quickSort->setNewTable(table);

            time->start();
            sortedTable = quickSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime << ";";
        }
        file << endl;
    }

    // sorted 33
    cout << "###################### 33 rand" << endl;
    for (int size = minSize; size <= maxSize; size += step) {
        cout << "################size: " << size << endl;
        for (int i = 0; i < 100; i++) {
            cout << i << endl;
            table->randomPercent(size, 33);
            quickSort->setNewTable(table);

            time->start();
            sortedTable = quickSort->sort();
            sortingTime = time->getTime();

            if (not sortedTable->isSorted()) {
                std::cout << "Sortowanie nie powiodło się" << std::endl;
                return;
            }

            file << sortingTime << ";";
        }
        file << endl;
    }


    file.close();
    delete quickSort;


    delete table;
    delete sortedTable;
}

