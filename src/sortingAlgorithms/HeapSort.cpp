
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
Table<T>* HeapSort<T>::start(){
    sortQuick(0, table->getSize()-1);
    return table;
}


template<typename T>
void HeapSort<T>::sortQuick(int left, int right){
    int i = int((left + right)/2);
    T piwot = table->get(i);
    table->set(i, table->get(right));
    int j = left;
    i = left;

    while(i<right){
        if(table->get(i)<piwot){
            table->swap(i, j);
            j++;
        }
        i++;
    }

    table->set(right, table->get(j));
    table->set(j, piwot);

    if(left<j-1){
        sortQuick(left, j-1);
    }

    if(j+1<right){
        sortQuick(j+1, right);
    }
}

// Deklaracja szablonów klasowych
template class HeapSort<int>;
template class HeapSort<float>;
template class HeapSort<unsigned long long>;