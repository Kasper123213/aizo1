
#ifndef AIZO1_AUTOTEST_H
#define AIZO1_AUTOTEST_H

#include <string>

using namespace std;
class AutoTest {
public:
    AutoTest();
    ~AutoTest();

private:
    template<typename T>
    void runTest();

};


#endif //AIZO1_AUTOTEST_H
