#include "Czas.h"

//włączanie "stopera", zapisywanie obecnego czasu do zmiennej startTime
void Czas::start() {
    czasPoczatkowy = high_resolution_clock::now();
}
//wyłączanie "stopera", zapisywanie obecnego czasu do zmiennej stopTime
void Czas::stop() {
    czasKoncowy = high_resolution_clock::now();
}

//odejmowanie czasu początkowego i koncowego w celu obliczenia czasu trwania algorytmu
long Czas::podajCzas() {
    stop();
    return duration_cast<milliseconds>(czasKoncowy - czasPoczatkowy).count();
}