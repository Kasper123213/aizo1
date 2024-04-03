
#ifndef AIZO1_QUICKSORT_H
#define AIZO1_QUICKSORT_H


#include "../structures/Table.h"

template<typename T>
class QuickSort {
private:
    Table<T> *table;

    void sortQuick(int left, int right);

public:
    QuickSort(Table<T> *table);

    ~QuickSort();

    void setNewTable(Table<T> *table);

    Table<T> *sort();
};


#endif //AIZO1_QUICKSORT_H
