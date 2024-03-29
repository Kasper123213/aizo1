
#include "InsertionSort.h"


template<typename T>
InsertionSort<T>::InsertionSort(Table<T>* table){
    this->table = new Table<T>();
    this->table->setSize(table->getSize());

    for(int i = 0; i<table->getSize(); i++){
        this->table->set(i, table->get(i));
    }
}

template<typename T>
InsertionSort<T>::~InsertionSort(){
}


template<typename T>
void InsertionSort<T>::setNewTable(Table<T> *table) {
    delete this->table;
    this->table = new Table<T>();
    this->table->setSize(table->getSize());

    for(int i = 0; i<table->getSize(); i++){
        this->table->set(i, table->get(i));
    }

}


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