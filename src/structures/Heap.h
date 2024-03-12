//
// Created by radom on 12.03.2024.
//

#ifndef AIZO1_HEAP_H
#define AIZO1_HEAP_H

template<typename T>
class Heap {
public:

    Heap();

    ~Heap();

    void add(T value);

    T getRoot();

    bool doesExist(T value);

    void print();


    int getSize();

private:
    T *table = nullptr;
    int size = 0;


    void sortAfterAdding();

    void sortAfterRemoving(int index = 1);
};


#endif //AIZO1_HEAP_H
