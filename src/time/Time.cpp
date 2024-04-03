#include "Time.h"

//włączanie "stopera", zapisywanie obecnego czasu do zmiennej startTime
void Time::start() {
    startTime = high_resolution_clock::now();
}

//wyłączanie "stopera", zapisywanie obecnego czasu do zmiennej stopTime
void Time::stop() {
    endTime = high_resolution_clock::now();
}

//odejmowanie czasu początkowego i koncowego w celu obliczenia czasu trwania algorytmu
long Time::getTime() {
    stop();
    return duration_cast<milliseconds>(endTime - startTime).count();
}