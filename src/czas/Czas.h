#include <iostream>
#include <chrono>

#ifndef PEA1_TIME_H
#define PEA1_TIME_H

using namespace std;
using namespace std::chrono;
class Czas {
private:
    high_resolution_clock::time_point czasPoczatkowy;
    high_resolution_clock::time_point czasKoncowy;


public:
    void start();

    void stop();

    long podajCzas();
};


#endif //PEA1_TIME_H