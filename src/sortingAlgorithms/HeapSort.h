//
// Created by radom on 12.03.2024.
//

#ifndef AIZO1_HEAPSORT_H
#define AIZO1_HEAPSORT_H

#include "../structures/Table.h"
#include "../structures/Heap.h"

template<typename T>
class HeapSort {
private:
    Table<T>* table;

public:
    HeapSort(Table<T>* table);
    ~HeapSort();

    Table<T>* sort();
};


#endif //AIZO1_HEAPSORT_H
