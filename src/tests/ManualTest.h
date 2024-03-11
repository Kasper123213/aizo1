
#ifndef AIZO1_MANUALTEST_H
#define AIZO1_MANUALTEST_H



#include "../table/Table.h"
#include <random>

class ManualTest {
private:

    Table* table = new Table();
    Table* sortedTable = new Table();



public:
    ManualTest();
    ~ManualTest();

    bool readFromFile(std::string);
    bool isSorted();

    void generateTable(int size, int generatingType);
    void randomFULL(int size);

};


#endif //AIZO1_MANUALTEST_H
