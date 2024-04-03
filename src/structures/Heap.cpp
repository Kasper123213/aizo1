
//kopiec maksymalny
#include <iostream>
#include "Heap.h"

using namespace std;

//konstruktor kopca
template<typename T>
Heap<T>::Heap() {
}

//destruktor kopca
template<typename T>
Heap<T>::~Heap() {

    if (size > 0) {   //jesli tablica zawiera jakis element to usuwamy tablice
        delete[]table;
    }

}

template<typename T>
void Heap<T>::set(int index, T value) {
    table[index] = value;
}

template<typename T>
void Heap<T>::sortAfterSetting() {
    for (int i = 2; i <= size; i++) {
        int j = i;
        int k = j / 2;
        T x = table[i - 1];

        while (k > 0 and table[k - 1] < x) {
            table[j - 1] = table[k - 1];
            j = k;
            k = j / 2;
        }
        table[j - 1] = x;
    }
}

template<typename T>
void Heap<T>::setSize(int size) {
    this->size = size;
    this->table = new T[size];
}


template<typename T>
T Heap<T>::getRoot() {
    T root = table[0];
    table[0] = table[size - 1];  //usuwamy kkorzen dajac na jego imiejsce ostatni element tablicy
    T *newTable = new T[size - 1];  //tworzymy nowa tablice
    for (int i = 0; i < size - 1; i++) {
        newTable[i] = table[i];//przepisujemy watrosci starej tablicy na nowa poza ostatnim elementem
    }
    delete[] table;   //usuwanie starej tablicy

    table = newTable; //przypisywanie tablicy do zmiennej globalnej

    size--;  //inkrementacja rozmiaru tablicy

    sortAfterRemoving(); //przywracamy wlasnosc kopca

    return root; //zwracania największej wartości w kopcu
}


template<typename T>
void Heap<T>::sortAfterRemoving(int index) {
    int newIndex;   //zmienna pomocnicza
    if (index * 2 > size) { //sprawdzamy czy wezel niema potomkow
        return;
    } else if (index * 2 + 1 > size) {//jesli ma tylko lewego potomka, ustawiamy na niego wskaznik pomocniczy
        newIndex = index * 2;
    } else {     //jesli ma obu potomkow ustawiamy wskaznik na wiekszego
        newIndex = table[2 * index - 1] < table[index * 2] ? index * 2 + 1 : index * 2;
    }

    T value = table[newIndex - 1];
    if (value > table[index - 1]) {   //sprawdzamy czy syn z najwieksza wartoscia ma wieksza wartosc od ojca
        table[newIndex - 1] = table[index - 1];   //jesli tak to zamieniamy ich miejscami i porzadkujemy dalej
        table[index - 1] = value;
        sortAfterRemoving(newIndex);
    }

}

template<typename T>
int Heap<T>::getSize() { return size; }  //metoda zwracajaca ilosc wezlow w kopcu


// Deklaracja szablonów klasowych
template
class Heap<int>;

template
class Heap<float>;