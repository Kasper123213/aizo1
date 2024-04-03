
#ifndef AIZO1_BINARYINSERTIONSORT_H
#define AIZO1_BINARYINSERTIONSORT_H

#include "../structures/Table.h"


template<typename T>
class BinaryInsertionSort {
private:
    Table<T> *table;

public:
    BinaryInsertionSort(Table<T> *table);

    ~BinaryInsertionSort();

    void setNewTable(Table<T> *table);

    Table<T> *sort();
};


#endif //AIZO1_BINARYINSERTIONSORT_H
