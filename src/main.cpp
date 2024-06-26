#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include "tests/ManualTest.h"
#include "tests/AutoTest.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);    //ustawianie polskich znaków


    srand(time(NULL)); //inicjacja generatora liczb pseudolosowych


    cout << "Autor: Kasper Radom 264023" << endl << endl;

    int choice = 0;

    do {
        cout << "Jaki rodzaj testów wybierasz?" << endl
             << "\t1. Testy manualne" << endl
             << "\t2. Testy automatyczne" << endl
             << "\t0. Zakończenie działania programu" << endl
             << ">>";

        cin >> choice;

        if (choice == 1) {
            int dataType = 1;

            cout << "Na jakim typie danych chcesz operować?" << endl
                 << "\t1. int" << endl
                 << "\t2. float" << endl
                 << ">>";

            cin >> dataType;
            //inicjowanie pamięci na włączenie testów
            switch (dataType) {
                case 1: {
                    ManualTest<int> *test = new ManualTest<int>();
                    delete test;
                    break;
                }
                case 2: {
                    ManualTest<float> *test = new ManualTest<float>();
                    delete test;
                    break;
                }
            }


        } else if (choice == 2) {
            //inicjowanie pamięci na włączenie testów
            AutoTest *test = new AutoTest;

            delete test;
        }
    } while (choice != 0);

    return 0;
}