#include <iostream>
#include "Table.h"

using namespace std;


Table::Table() {     //ustawianie atrybutów tablicy
    Table::tableSize = 0;
    Table::head = nullptr;
}

Table::~Table() {   //zwalnianie pamięci po tablicy
    if (head != nullptr) {
        delete[]head;
    }
    tableSize = 0;

}


int Table::getSize() { return tableSize; }

//metoda dodająca element na początek tablicy
void Table::addHead(int value) {
    int *newHead = new int[tableSize + 1];   //ustawianie nowego wskaznika na nowa, wiekszą tablice

    for (int i = 0; i < tableSize; i++) {         //wstawianie elementow starej tablicy
        newHead[i + 1] = head[i];              //"i+1" bo index 0 nowej tablicy zostawiamy na podana value
    }

    newHead[0] = value;                          //dodwanie podanej valuei na head nowej tablicy
    tableSize++;                                  //inkrementacja zmiennej okreslajacaj dlugosc tablicy
    delete[] head;                                  //zawalnianie miejsca po poprzedniej tablicy
    head = newHead;                            //ustawianie wskaznika poczatku starej tablicy na nowa tablice
}


//metoda dodająca element na koniec tablicy
void Table::addEnd(int value) {
    int *newHead = new int[tableSize + 1];   //ustawianie nowego wskaznika na nowa, wiekszą tablice

    for (int i = 0; i < tableSize; i++) {         //wstawianie elementow starej tablicy
        newHead[i] = head[i];
    }

    newHead[tableSize] = value;            //dodwanie podanej valuei na koniec nowej tablicy
    tableSize++;                                  //inkrementacja zmiennej okreslajacaj dlugosc tablicy
    delete[] head;                                  //zawalnianie miejsca po poprzedniej tablicy
    head = newHead;                            //ustawianie wskaznika poczatku starej tablicy na nowa tablice

}


//metoda dodająca element na wybrany index tablicy
void Table::addOnIndex(int index, int value) {
    if(index<0 || index>tableSize) {   //sprawdzanie czy podano poprawny index
        return;
    }

    int *newHead = new int[tableSize + 1];   //ustawianie nowego wskaznika na nowa, wiekszą tablice
    for (int i = 0; i <
                    index; i++) {                  //wstawianie elementow ktore powinny znalezc sie na indexach mniejszych niz podany
        newHead[i] = head[i];
    }
    newHead[index] = value;                     //dodawanie podanej valuei na podany index
    for (int i = index + 1; i < tableSize +
                                 1; i++) {//wstawianie elementow ktore powinny znalezc sie na indexach wiekszych niz podany
        newHead[i] = head[i - 1];
    }
    tableSize++;                                  //inkrementacja zmiennej okreslajacaj dlugosc tablicy
    delete[] head;                                  //zawalnianie miejsca po poprzedniej tablicy
    head = newHead;                            //ustawianie wskaznika poczatku starej tablicy na nowa tablice
}


//metoda usuwajaca element z poczatku tablicy
void Table::deleteFirst() {
    if(tableSize<=0){ //sprawdzanie czy tablica jest pusta
        return;
    }

    int *newHead = new int[tableSize - 1];   //ustawianie nowego wskaznika na nowa, wiekszą tablice
    for (int i = 1;
         i < tableSize; i++) {         //wstawianie elementow starej tablicy z pominieciem pierwszego elementu
        newHead[i - 1] = head[i];
    }
    tableSize--;                                  //dekrementacja zmiennej okreslajacaj dlugosc tablicy
    delete[] head;                                  //zawalnianie miejsca po poprzedniej tablicy
    head = newHead;                            //ustawianie wskaznika poczatku starej tablicy na nowa tablice
}


//metoda usuwajaca element z konca tablicy
void Table::deleteLast() {
    if(tableSize<=0){ //sprawdzanie czy tablica jest pusta
        return;
    }

    int *newHead = new int[tableSize - 1];   //ustawianie nowego wskaznika na nowa, wiekszą tablice
    for (int i = 0;
         i < tableSize - 1; i++) {     //wstawianie elementow starej tablicy z pominieciem ostatniego elementu
        newHead[i] = head[i];
    }
    tableSize--;                                  //dekrementacja zmiennej okreslajacaj dlugosc tablicy
    delete[] head;                                  //zawalnianie miejsca po poprzedniej tablicy
    head = newHead;                            //ustawianie wskaznika poczatku starej tablicy na nowa tablice

}


//metoda usuwajaca element o podanym indexie z tablicy
void Table::deleteIndex(int index) {
    if(index<0 || index>=tableSize || tableSize <=0){ //sprawdzanie czy podano poprawny index
        return;
    }
    int *newHead = new int[tableSize - 1];   //ustawianie nowego wskaznika na nowa, wiekszą tablice
    for (int i = 0;
         i < index; i++) {                  //wstawianie elementow starej tablicy od poczatku do podanego indexu
        newHead[i] = head[i];
    }
    for (int i = index + 1;
         i < tableSize; i++) {  //wstawianie elementow starej tablicy od podanego indexu do konca
        newHead[i - 1] = head[i];
    }
    tableSize--;                                  //dekrementacja zmiennej okreslajacaj dlugosc tablicy
    delete[] head;                                  //zawalnianie miejsca po poprzedniej tablicy
    head = newHead;                            //ustawianie wskaznika poczatku starej tablicy na nowa tablice

}


//metoda wyszukujaca pierwszy element o podanej valuei z tablicy i zwracajaca jego index,
// jesli elementu niema w tablicy, zwraca -1
int Table::searchValue(int value) {
    for (int i = 0; i < tableSize; i++) {                 //po kolei sprawdzamy czy i-ty element jest rowny podanej valuei
        if (head[i] == value)return i;
    }
    return -1;                                          //jesli elementu niema w tablicy zwraca -1
}


//metoda drujukujaca kolejne elementy tablicy w formacie [i] T[i]
void Table::printTable() {
    if (tableSize <= 0) {
        cout << "Table pusta" << endl;
        return;
    }
    cout << "Kolejność normalna:" << endl;
    for (int i = 0; i < tableSize; i++) {
        cout << head[i] << ", ";
    }
    cout << endl;
    cout << "Kolejność odwrotna:" << endl;
    for (int i = 0; i < tableSize; i++) {
        cout << head[tableSize - 1 - i] << ", ";
    }
    cout << endl;
}

void Table::setTable(int *newTable, int size) {
    delete[]head;
    head = newTable;
    tableSize=size;
}

void Table::clearTable() {

}

int Table::get(int index){
    return head[index];
}