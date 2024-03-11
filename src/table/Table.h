
#ifndef AIZO1_TABLE_H
#define AIZO1_TABLE_H

template<typename T>
class Table{
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

    //metoda dodająca element na początek tablicy
    void addHead(T value);

    //metoda dodająca element na koniec tablicy
    void addEnd(T value);

    //metoda dodająca element na wybrany indeks tablicy
    void addOnIndex(int index, T value);

    //metoda usuwajaca element z poczatku tablicy
    void deleteFirst();

    //metoda usuwajaca element z konca tablicy
    void deleteLast();

    //metoda usuwajaca element o podanym indeksie z tablicy
    void deleteIndex(int index);

    //metoda wyszukujaca pierwszy element o podanej wartości z tablicy i zwracajaca jego indeks,
    // jesli elementu niema w tablicy, zwraca -1
    T searchValue(T value);

    //metoda drujukujaca kolejne elementy tablicy w formacie [i]{T[i]}
    void printTable();

    //zwraca dlugosc tablicy
    int getSize();

    //ustawianie tablicy
    void setTable(T *nowaTablica, int rozmiar);

    //czyszczenie tablicy
    void clear();

    //Zwraca element tablicy
    T get(int index);
};


#endif //AIZO1_TABLE_H