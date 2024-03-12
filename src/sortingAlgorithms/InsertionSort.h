
#ifndef AIZO1_INSERTIONSORT_H
#define AIZO1_INSERTIONSORT_H

#include "../structures/Table.h"

template<typename T>
class InsertionSort {
private:
    Table<T>* table;

public:
    InsertionSort(Table<T>* table);
    ~InsertionSort();

    Table<T>* sort();
};


#endif //AIZO1_INSERTIONSORT_H
