
#ifndef AIZO1_TABLE_H
#define AIZO1_TABLE_H

template<typename T>
class Table {
private:
    //wakaznik na początek tablicy
    T *head;
    //dlugosc tablicy / liczba elementow
    int tableSize;


public:
    //ustawianie atrybutów tablicy
    Table();

    //zwalnianie pamięci po tablicy
    ~Table();

    //metoda dodająca element na koniec tablicy
    void addEnd(T value);

    //metoda drujukujaca kolejne elementy tablicy w formacie [i]{T[i]}
    void printTable();

    //zwraca dlugosc tablicy
    int getSize();

    //czyszczenie tablicy
    void clear();

    //Zwraca element tablicy
    T get(int index);

    void swap(int i, int j);

    void set(int i, T value);

    void setSize(int size);

    void randomFULL(int size);

    void randomPercent(int size, int percent);

    void randomDescending(int size);

    bool isSorted();

};


#endif //AIZO1_TABLE_H