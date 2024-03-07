#include "Czas.h"

//włączanie "stopera", zapisywanie obecnego czasu do zmiennej startTime
void Czas::start() {
    startTime = high_resolution_clock::now();
}
//wyłączanie "stopera", zapisywanie obecnego czasu do zmiennej stopTime
void Czas::stop() {
    endTime = high_resolution_clock::now();
}

//odejmowanie czasu początkowego i koncowego w celu obliczenia czasu trwania algorytmu
long Czas::getTime() {
    stop();
    return duration_cast<milliseconds>(endTime - startTime).count();
}