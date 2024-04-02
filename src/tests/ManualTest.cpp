#include <iostream>
#include <fstream>
#include <typeinfo>
#include "ManualTest.h"
#include "../sortingAlgorithms/QuickSort.h"
#include "../sortingAlgorithms/HeapSort.h"
#include "../sortingAlgorithms/InsertionSort.h"
#include "../sortingAlgorithms/BinaryInsertionSort.h"
#include "../time/Time.h"


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
            <<"\t7. Zapisz tablicę po posortowaniu do pliku txt"<<endl
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
                table->printTable();
                break;
            }
            case 4: {
                if (sortedTable->isSorted()) {
                    cout << "Tablica posortowana poprawnie" << endl;
                } else {
                    cout << "Tablica posortowana niepoprawnie" << endl;
                }
                break;
            }
            case 5: {
                cout << "Wybierz rodzaj algorytmu sortującego:" << endl
                     << "\t1. Sortowanie przez wstawianie (zwykłe)" << endl
                     << "\t2. Sortowanie przez wstawianie (binarne)" << endl
                     << "\t3. Sortowanie przez kopcowanie" << endl
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
            case 7: {
                saveSolution();
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
    table->clear();
    sortedTable->clear();

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
void ManualTest<T>::generateTable(int size, int generatingType) {
    sortedTable->clear();
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
            table->randomPercent(size, 100);
            break;
    }
}


template<typename T>
void ManualTest<T>::sort(int sortingType) {
    Time* time = new Time();
    //  sortowanie przez wstawianie zwykłe i binarne, przez kopcowanie (heap sort) i szybkie
    switch (sortingType) {
        case 1:{
            InsertionSort<T>* insertionSort = new InsertionSort(table);

            time->start();
            sortedTable = insertionSort->sort();
            long exTime = time->getTime();
            cout<< "Czas wykonania algorytmu: "<<exTime<<"ms"<<endl;

            delete insertionSort;
            break;
        }
        case 2:{
            BinaryInsertionSort<T>* binaryInsertionSort = new BinaryInsertionSort(table);

            time->start();
            sortedTable = binaryInsertionSort->sort();
            long exTime = time->getTime();
            cout<< "Czas wykonania algorytmu: "<<exTime<<"ms"<<endl;

            delete binaryInsertionSort;
            break;
        }
        case 3:{
            HeapSort<T>* heapSort = new HeapSort(table);

            time->start();
            sortedTable = heapSort->sort();
            long exTime = time->getTime();
            cout<< "Czas wykonania algorytmu: "<<exTime<<"ms"<<endl;

            delete heapSort;
            break;
        }
        case 4: {
            QuickSort<T> *quickSort = new QuickSort(table);

            time->start();
            sortedTable = quickSort->sort();
            long exTime = time->getTime();
            cout<< "Czas wykonania algorytmu: "<<exTime<<"ms"<<endl;

            delete quickSort;
            break;
        }
    }
    delete time;
}



//zapisanie rozwiązania do pliku
template<typename T>
void ManualTest<T>::saveSolution(){
    int index = 1;
    string name ;
    while(true){
        name = "sortedList" + to_string(index) + ".txt";
        ifstream file(name);
        break; //todo usunąć to
        if(not file.good()) break;
        index++;
    }

    string solutionFile = name;
    string unsortedFile = "unsortedList" + to_string(index) + ".txt";

    // Otwarcie pliku w trybie do zapisu (truncation)
//    ofstream file(solutionFile, ios::trunc);//todo usunąć to tak jak bylo
    ofstream file1(unsortedFile, ios::trunc);

    // Sprawdzenie, czy plik został otwarty poprawnie
    if (file1.is_open()) {

        for(int i=0; i< table->getSize(); i++){
//            file << sortedTable->get(i) <<endl;
            file1 << table->get(i) <<endl;
        }

        // Zamknięcie pliku
//        file.close();
        file1.close();

        cout << "Zapisano do pliku." << endl;
    } else {
        cout << "Błąd podczas otwierania pliku." << endl;
    }
}


// Deklaracja szablonów klasowych
template class ManualTest<int>;
template class ManualTest<float>;