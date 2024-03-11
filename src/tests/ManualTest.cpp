#include <iostream>
#include <fstream>
#include <typeinfo>
#include "ManualTest.h"
#include "../sortingAlgorithms/QuickSort.h"


using namespace std;

template<typename T>
ManualTest<T>::ManualTest(){
    int choice = 0;
    string path;
    do{

        cout<<"Wybierz co chcesz zrobić:"<<endl
            <<"\t1. Wczytaj z pliku tablicę do posortowanie"<<endl
            <<"\t2. Wygeneruj losową tablicę do posortowanie"<<endl
            <<"\t3. Pokaż tablicę nieposortowaną (ostatnia wczytana lub wygenerowana)"<<endl
            <<"\t4. Sprawdź czy tablica po posortowaniu jest posortowana prawidłowo"<<endl
            <<"\t5. Uruchom algorytm sortujący"<<endl
            <<"\t6. Pokaż tablicę po posortowaniu"<<endl
            <<"\t0. Wyjdź z menu"<<endl
            <<">>";

        cin>>choice;

        switch (choice) {
            case 1: {
                cout << "Podaj ścieżkę do pliku z danymi do posortowania:\n>>";
                cin >> path;

                if (not readFromFile(path)) {
                    cout << "Nie udało się wczytać danych z podanego pliku";
                }
                break;
            }
            case 2: {
                cout << "Podaj rozmiar tablicy, którą chcesz wygenerować:\n>>";
                int size;
                cin >> size;

                cout << "Wybierz tryb losowanie tablicy:" << endl
                     << "\t1. Tablica całkowicie losowa" << endl
                     << "\t2. Tablica mająca posortowane pierwsze 33%" << endl
                     << "\t3. Tablica mająca posortowane pierwsze 66%" << endl
                     << "\t4. Tablica posortowana malejąco" << endl
                     << "\t5. Tablica posortowana rosnąco\n>>";

                int generatingType;
                cin >> generatingType;

                generateTable(size, generatingType);
                break;
            }
            case 3: {
                if (table->getSize() > 20) cout << "Tablica za duża na wyświetlenie";
                table->printTable();
                break;
            }
            case 4: {
                if (isSorted()) {
                    cout << "Tablica posortowana poprawnie" << endl;
                } else {
                    cout << "Tablica posortowana niepoprawnie" << endl;
                }
                break;
            }
            case 5: {
                cout << "Wybierz rodzaj algorytmu sortującego:" << endl
                     << "\t1. Sortowanie przez wstawianie" << endl
                     << "\t2. Sortowanie przez kopcowanie" << endl
                     << "\t3. Sortowanie Shella" << endl
                     << "\t4. Sortowanie szybkie\n>>";

                int sortingType = 1;
                cin >> sortingType;

                sort(sortingType);
                break;
            }
            case 6: {
                if (sortedTable->getSize() > 20) cout << "Tablica za duża na wyświetlenie";
                else sortedTable->printTable();
                break;
            }
        }

    }while(choice != 0);
}

template<typename T>
ManualTest<T>::~ManualTest() {
    delete table;
    delete sortedTable;
}


template<typename T>
bool ManualTest<T>::readFromFile(string path){
    path = "C:\\Users\\radom\\OneDrive\\Pulpit\\aizo\\aizo1\\testTables\\table1.txt";
    table->clear();

    // Otwórz plik
    ifstream file(path);

    // Sprawdź, czy udało się otworzyć plik
    if (!file.is_open()) {
        return false;
    }

    // Zmienna przechowująca wartość wczytaną z pliku
    T word;

    // Wyczyść flagi błędów i pozycję odczytu pliku
    file.clear();
    file.seekg(0, ios::beg);

    //Wczytywanie danych z pliku
    while (file >> word) {
        table->addEnd(word);
    }

    file.close();
    return true;
}


template<typename T>
bool ManualTest<T>::isSorted() {
    if(sortedTable->getSize() == 0){
        cout<<"Nie uruchomiono algorytmu sortowania. Tablica posortowana jest pusta"<<endl;
        return false;
    }else if(sortedTable->getSize() == 1){
        return true;
    }


    T first = sortedTable->get(0);
    T second;

    for(int index=1; index<sortedTable->getSize(); index++){
        second = sortedTable->get(index);

        if(first > second)return false;

        first = second;
    }

    return true;
}


template<typename T>
void ManualTest<T>::generateTable(int size, int generatingType) {
    table->clear();
    //losowo, 33, 66, malejąco, rosnąco
    switch (generatingType) {
        case 1:
            table->randomFULL(size);
            break;

        case 2:
            table->randomPercent(size, 33);
            break;

        case 3:
            table->randomPercent(size, 66);
            break;

        case 4:
            table->randomDescending(size);
            break;

        case 5:
            table->randomGrowing(size);
            break;
    }
}


template<typename T>
void ManualTest<T>::sort(int sortingType) {//todo pomiary czasu
    // sortowanie przez wstawianie, przez kopcowanie, Shella i szybkie
    switch (sortingType) {
        case 1:{//todo
            break;
        }
        case 2:{//todo
            break;
        }
        case 3:{//todo
            break;
        }
        case 4:{
            QuickSort<T>* quickSort = new QuickSort(table);
            sortedTable = quickSort->start();
            delete quickSort;
            break;
        }

    }
}


// Deklaracja szablonów klasowych
template class ManualTest<int>;
template class ManualTest<float>;
template class ManualTest<unsigned long long>;