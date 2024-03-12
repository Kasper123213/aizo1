
#ifndef AIZO1_BINARYINSERTIONSORT_H
#define AIZO1_BINARYINSERTIONSORT_H

#include "../structures/Table.h"

template<typename T>
class BinaryInsertionSort {
private:
    Table<T>* table;

public:
    BinaryInsertionSort(Table<T>* table);
    ~BinaryInsertionSort();

    Table<T>* sort();
};


#endif //AIZO1_BINARYINSERTIONSORT_H
