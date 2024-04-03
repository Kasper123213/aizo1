
#include "QuickSort.h"

//konstruktor klasy
template<typename T>
QuickSort<T>::QuickSort(Table<T> *table) {
    this->table = new Table<T>();
    this->table->setSize(table->getSize());

    for (int i = 0; i < table->getSize(); i++) {
        this->table->set(i, table->get(i));
    }
}

//destruktoor może być pusty, gdyż utworzona w konstruktorzze zmienna table jest wylącznie wskaźnikiem na klasę,
// której destróktor wywoływany jest w innym miejscu
template<typename T>
QuickSort<T>::~QuickSort() {
}

//zmiana danych w tablicy
//użyteczne przy testowaniu automatycznym
template<typename T>
void QuickSort<T>::setNewTable(Table<T> *table) {
    delete this->table;
    this->table = new Table<T>();
    this->table->setSize(table->getSize());

    for (int i = 0; i < table->getSize(); i++) {
        this->table->set(i, table->get(i));
    }
}

//funkcja wywołuje główną funkcję sortującą z odpowiednimi argumentami. pozwala to następnie
// wywoływać ją rekurencyjnie dla innych argumentów
template<typename T>
Table<T> *QuickSort<T>::sort() {
    sortQuick(0, table->getSize() - 1);
    return table;
}

//główna funkcja sortująca algorytmem przez wstawianie binarne
template<typename T>
void QuickSort<T>::sortQuick(int left, int right) {
    int i = int((left + right) / 2);
    T piwot = table->get(i);
    table->set(i, table->get(right));
    int j = left;
    i = left;

    while (i < right) {
        if (table->get(i) < piwot) {
            table->swap(i, j);
            j++;
        }
        i++;
    }
    table->set(right, table->get(j));
    table->set(j, piwot);
    if (left < j - 1) {
        sortQuick(left, j - 1);
    }
    if (j + 1 < right) {
        sortQuick(j + 1, right);
    }
}

// Deklaracja szablonów klasowych
template
class QuickSort<int>;

template
class QuickSort<float>;