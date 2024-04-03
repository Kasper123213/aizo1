
#ifndef AIZO1_HEAP_H
#define AIZO1_HEAP_H

#include "Table.h"

template<typename T>
class Heap {
public:

    Heap();

    ~Heap();

    void set(int index, T value);

    void sortAfterSetting();

    void setSize(int size);

    T getRoot();


    int getSize();

private:
    T *table = nullptr;
    int size = 0;

    void sortAfterRemoving(int index = 1);
};


#endif //AIZO1_HEAP_H
