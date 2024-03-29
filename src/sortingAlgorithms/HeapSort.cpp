#include <iostream>
#include "HeapSort.h"


template<typename T>
HeapSort<T>::HeapSort(Table<T>* table){
    this->table = new Table<T>();
    this->table->setSize(table->getSize());

    for(int i = 0; i<table->getSize(); i++){
        this->table->set(i, table->get(i));
    }
}

template<typename T>
HeapSort<T>::~HeapSort(){
}


template<typename T>
void HeapSort<T>::setNewTable(Table<T> *table) {
    delete table;
    table = new Table<T>();
    this->table->setSize(table->getSize());

    for(int i = 0; i<table->getSize(); i++){
        this->table->set(i, table->get(i));
    }
}


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