//
// Created by radom on 12.03.2024.
//

#ifndef AIZO1_SHELLSORT_H
#define AIZO1_SHELLSORT_H

#include "../table/Table.h"

template<typename T>
class ShellSort {
private:
    Table<T>* table;

public:
    ShellSort(Table<T>* table);
    ~ShellSort();

    Table<T>* start();
};


#endif //AIZO1_SHELLSORT_H
