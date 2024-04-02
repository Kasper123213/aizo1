
#include "BinaryInsertionSort.h"

//konstruktor klasy
template<typename T>
BinaryInsertionSort<T>::BinaryInsertionSort(Table<T> *table) {
    this->table = new Table<T>();
    this->table->setSize(table->getSize());

    for (int i = 0; i < table->getSize(); i++) {
        this->table->set(i, table->get(i));
    }
}

//destruktoor może być pusty, gdyż utworzona w konstruktorzze zmienna table jest wylącznie wskaźnikiem na klasę,
// której destróktor wywoływany jest w innym miejscu
template<typename T>
BinaryInsertionSort<T>::~BinaryInsertionSort() {
}

//zmiana danych w tablicy
//użyteczne przy testowaniu automatycznym
template<typename T>
void BinaryInsertionSort<T>::setNewTable(Table<T> *table) {
    delete this->table;
    this->table = new Table<T>();
    this->table->setSize(table->getSize());

    for (int i = 0; i < table->getSize(); i++) {
        this->table->set(i, table->get(i));
    }
}

//główna funkcja sortująca algorytmem przez wstawianie binarne
template<typename T>
Table<T> *BinaryInsertionSort<T>::sort() {
    int ip, ik, i, j = table->getSize() - 2;
    T x;

    for (; j >= 0; j--) {
        x = table->get(j);
        ip = j;
        ik = table->getSize();
        while (ik - ip > 1) {
            i = (ip + ik) / 2;
            if (x <= table->get(i)) ik = i;
            else ip = i;
        }
        for (i = j; i < ip; i++)table->set(i, table->get(i + 1));
        table->set(ip, x);
    }
    return table;
}


// Deklaracja szablonów klasowych
template
class BinaryInsertionSort<int>;

template
class BinaryInsertionSort<float>;