//
// Created by radom on 12.03.2024.
//

#include "ShellSort.h"


template<typename T>
ShellSort<T>::ShellSort(Table<T> *table) {
    this->table = new Table<T>();
    for (int i = 0; i < table->getSize(); i++) {
        this->table->addEnd(table->get(i));
    }
}

template<typename T>
ShellSort<T>::~ShellSort() {
}

template<typename T>
Table<T> *ShellSort<T>::start() {
    int h = 1;
    do {
        h = 3 * h + 1;
    } while (h <= table->getSize());

    h = int(h / 9);
    if (h == 0) h = 1;

    int j, i;
    T x;
    while (h > 0) {
        for (j = table->getSize() - h; j >= 0; j--) {
            x = table->get(j);
            i = j + h;

            while (i <= table->getSize() and x > table->get(i)) {
                table->set(i - h, table->get(i));
                i += h;
            }
            table->set(i - h, x);
        }
        h = int(h / 3);
    }


    return table;
}


// Deklaracja szablonów klasowych
template
class ShellSort<int>;

template
class ShellSort<float>;

template
class ShellSort<unsigned long long>;