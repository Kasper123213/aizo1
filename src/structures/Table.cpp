#include <iostream>
#include <random>
#include <limits>
#include "Table.h"

using namespace std;

template<typename T>
Table<T>::Table() {     //ustawianie atrybutów tablicy
    Table<T>::tableSize = 0;
    Table<T>::head = nullptr;
}

template<typename T>
Table<T>::~Table() {   //zwalnianie pamięci po tablicy
    if (head != nullptr) {
        delete[]head;
        head = nullptr;
    }
    tableSize = 0;

}


template<typename T>
int Table<T>::getSize() { return tableSize; }


//metoda dodająca element na koniec tablicy
template<typename T>
void Table<T>::addEnd(T value) {
    T *newHead = new T[tableSize + 1];   //ustawianie nowego wskaznika na nowa, wiekszą tablice

    for (int i = 0; i < tableSize; i++) {         //wstawianie elementow starej tablicy
        newHead[i] = head[i];
    }

    newHead[tableSize] = value;            //dodwanie podanej valuei na koniec nowej tablicy
    tableSize++;                                  //inkrementacja zmiennej okreslajacaj dlugosc tablicy
    delete[] head;                                  //zawalnianie miejsca po poprzedniej tablicy
    head = newHead;                            //ustawianie wskaznika poczatku starej tablicy na nowa tablice

}


//metoda drujukujaca kolejne elementy tablicy w formacie [i] T[i]
template<typename T>
void Table<T>::printTable() {
    if (tableSize > 20) {
        cout << "Tablica za duża na wyświetlenie :" << tableSize << " elementów" << endl;
        return;
    }
    cout << "####################################################################################" << endl;
    if (tableSize <= 0) {
        cout << "Tablica pusta" << endl;
        return;
    }
    for (int i = 0; i < tableSize; i++) {
        cout << head[i] << ", ";
    }
    cout << endl;
    cout << "####################################################################################" << endl;
}

template<typename T>
void Table<T>::clear() {
    delete[]head;
    head = nullptr;
    tableSize = 0;

}

template<typename T>
T Table<T>::get(int index) {
    return head[index];
}

template<typename T>
void Table<T>::randomFULL(int size) {
    setSize(size);
    random_device rd;
    mt19937 gen(rd());
    T max, min;


    max = numeric_limits<T>::max();
    min = numeric_limits<T>::min();


    if constexpr (is_same<float, T>::value || is_same<double, T>::value) {
        uniform_real_distribution<T> dis(min, max);
        for (int i = 0; i < size; i++) {
            head[i] = dis(gen);
        }
    } else {
        uniform_int_distribution<T> dis(min, max);
        for (int i = 0; i < size; i++) {
            head[i] = dis(gen);
        }
    }
}


template<typename T>
void Table<T>::randomPercent(int size, int percent) {
    setSize(size);
    random_device rd;
    mt19937 gen(rd());
    T max, min;
    T sorted = size * percent / 100;


    max = numeric_limits<T>::max();
    min = numeric_limits<T>::min();


    if constexpr (is_same<float, T>::value || is_same<double, T>::value) {
        for (int i = 0; i < sorted; i++) {
            head[i] = (i + 1) * min;
        }

        uniform_real_distribution<T> dis(min * sorted, max);
        for (int i = sorted; i < size; i++) {
            head[i] = dis(gen);
        }
    } else {
        for (int i = 0; i < sorted; i++) {
            head[i] = min + i;
        }


        uniform_int_distribution<T> dis(min + sorted, max);
        for (int i = sorted; i < size; i++) {
            head[i] = dis(gen);
        }
    }
}


template<typename T>
void Table<T>::randomDescending(int size) {
    setSize(size);

    if constexpr (is_same<float, T>::value || is_same<double, T>::value) {
        T min = numeric_limits<T>::min();

        for (int i = 1; i <= size; i++) {
            head[size - i] = (i) * min;
        }
    } else {
        T max = numeric_limits<T>::max();

        for (int i = 0; i < size; i++) {
            head[i] = max - i;
        }
    }

}

template<typename T>
void Table<T>::swap(int i, int j) {
    std::swap(head[i], head[j]);
}

template<typename T>
void Table<T>::set(int i, T value) {
    head[i] = value;
}

template<typename T>
void Table<T>::setSize(int size) {
    tableSize = size;
    delete[]head;
    head = new T[size];

}

template<typename T>
bool Table<T>::isSorted() {
    if (tableSize == 0) {
        cout << "Nie uruchomiono algorytmu sortowania. Tablica posortowana jest pusta" << endl;
        return false;
    } else if (tableSize == 1) {
        return true;
    }


    T first = get(0);
    T second;

    for (int index = 1; index < tableSize; index++) {
        second = get(index);

        if (first > second)return false;

        first = second;
    }

    return true;
}

// Deklaracja szablonów klasowych
template
class Table<int>;

template
class Table<float>;