
#include "HeapSort.h"


template<typename T>
HeapSort<T>::HeapSort(Table<T>* table){
    this->table = new Table<T>();
    for(int i = 0; i<table->getSize(); i++){
        this->table->addEnd(table->get(i));
    }
}

template<typename T>
HeapSort<T>::~HeapSort(){
}

template<typename T>
Table<T>* HeapSort<T>::sort(){
    Heap<T>* heap = new Heap<T>();

    for(int i=0; i<table->getSize(); i++){
        heap->add(table->get(i));
    }

    table->clear();

    while(heap->getSize()>0){
        table->addHead(heap->getRoot());
    }

    delete heap;
    return table;
}



// Deklaracja szablonów klasowych
template class HeapSort<int>;
template class HeapSort<float>;
template class HeapSort<unsigned long long>;