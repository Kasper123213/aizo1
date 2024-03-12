//
// Created by radom on 12.03.2024.
//

#ifndef AIZO1_HEAPSORT_H
#define AIZO1_HEAPSORT_H

#include "../table/Table.h"

template<typename T>
class HeapSort {
private:
    Table<T>* table;
    void sortQuick(int left, int right);

public:
    HeapSort(Table<T>* table);
    ~HeapSort();

    Table<T>* start();
};


#endif //AIZO1_HEAPSORT_H
