
#ifndef AIZO1_MANUALTEST_H
#define AIZO1_MANUALTEST_H



#include "../table/Table.h"
#include <random>

template<typename T>
class ManualTest {
private:

    Table<T>* table = new Table<T>();
    Table<T>* sortedTable = new Table<T>();



public:
    ManualTest();
    ~ManualTest();

    bool readFromFile(std::string);
    bool isSorted();

    void generateTable(int size, int generatingType);
    void randomFULL(int size);

    void sort();
};


#endif //AIZO1_MANUALTEST_H
