
#include "BinaryInsertionSort.h"



template<typename T>
BinaryInsertionSort<T>::BinaryInsertionSort(Table<T>* table){
    this->table = new Table<T>();
    for(int i = 0; i<table->getSize(); i++){
        this->table->addEnd(table->get(i));
    }
}

template<typename T>
BinaryInsertionSort<T>::~BinaryInsertionSort(){
}

template<typename T>
Table<T>* BinaryInsertionSort<T>::sort(){

    int ip, ik, i, j = table->getSize()-2;
    T x;

    for(; j>=0; j--){
        x = table->get(j);
        ip = j;
        ik = table->getSize();

        while(ik-ip>1){
            i = (ip + ik)/2;
            if(x<=table->get(i)) ik = i;
            else ip = i;
        }

        for(i=j; i<ip; i++)table->set(i, table->get(i+1));

        table->set(ip, x);
    }

    return table;
}



// Deklaracja szablonów klasowych
template class BinaryInsertionSort<int>;
template class BinaryInsertionSort<float>;
template class BinaryInsertionSort<unsigned long long>;