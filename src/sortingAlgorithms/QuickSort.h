
#ifndef AIZO1_QUICKSORT_H
#define AIZO1_QUICKSORT_H


#include "../table/Table.h"

template<typename T>
class QuickSort {
private:
    Table<T>* table;
    void sortQuick(int left, int right);

public:
    QuickSort(Table<T>* table);
    ~QuickSort();

    Table<T>* start();
};


#endif //AIZO1_QUICKSORT_H
