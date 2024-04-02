
#include "InsertionSort.h"

//konstruktor klasy
template<typename T>
InsertionSort<T>::InsertionSort(Table<T>* table){
    this->table = new Table<T>();
    this->table->setSize(table->getSize());

    for(int i = 0; i<table->getSize(); i++){
        this->table->set(i, table->get(i));
    }
}

//destruktoor może być pusty, gdyż utworzona w konstruktorzze zmienna table jest wylącznie wskaźnikiem na klasę,
// której destróktor wywoływany jest w innym miejscu
template<typename T>
InsertionSort<T>::~InsertionSort(){
}

//zmiana danych w tablicy
//użyteczne przy testowaniu automatycznym
template<typename T>
void InsertionSort<T>::setNewTable(Table<T> *table) {
    delete this->table;
    this->table = new Table<T>();
    this->table->setSize(table->getSize());

    for(int i = 0; i<table->getSize(); i++){
        this->table->set(i, table->get(i));
    }
}

//główna funkcja sortująca algorytmem przez wstawianie binarne
template<typename T>
Table<T>* InsertionSort<T>::sort(){
    T x;
    int i, j = table->getSize()-2;

    for(; j>=0 ; j--){
        x = table->get(j);
        i = j+1;
        while(i<table->getSize() and x>table->get(i)){
            table->set(i-1, table->get(i));
            i+=1;
        }
        table->set(i-1, x);
    }
    return table;
}



// Deklaracja szablonów klasowych
template class InsertionSort<int>;
template class InsertionSort<float>;