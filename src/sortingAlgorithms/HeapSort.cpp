#include <iostream>
#include "HeapSort.h"

//konstruktor klasy
template<typename T>
HeapSort<T>::HeapSort(Table<T>* table){
    this->table = new Table<T>();
    this->table->setSize(table->getSize());

    for(int i = 0; i<table->getSize(); i++){
        this->table->set(i, table->get(i));
    }
}

//destruktoor może być pusty, gdyż utworzona w konstruktorzze zmienna table jest wylącznie wskaźnikiem na klasę,
// której destróktor wywoływany jest w innym miejscu
template<typename T>
HeapSort<T>::~HeapSort(){
}

//zmiana danych w tablicy
//użyteczne przy testowaniu automatycznym
template<typename T>
void HeapSort<T>::setNewTable(Table<T> *table) {
    delete this->table;
    this->table = new Table<T>();
    this->table->setSize(table->getSize());

    for(int i = 0; i<table->getSize(); i++){
        this->table->set(i, table->get(i));
    }
}

//główna funkcja sortująca algorytmem przez wstawianie binarne
template<typename T>
Table<T>* HeapSort<T>::sort(){
    Heap<T>* heap = new Heap<T>();

    heap->setSize(table->getSize());
    for(int i = 0; i<table->getSize(); i++){
        heap->set(i, table->get(i));
    }
    heap->sortAfterSetting();
    for(int index = heap->getSize()-1; index>=0; index--){
        table->set(index, heap->getRoot());
    }
    delete heap;
    return table;
}



// Deklaracja szablonów klasowych
template class HeapSort<int>;
template class HeapSort<float>;