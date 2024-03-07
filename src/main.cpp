#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include "testy/TestyManualne.h"
#include "testy/TestyAutomatyczne.h"

using namespace std;
int main() {
    SetConsoleOutputCP(CP_UTF8);    //ustawianie polskich znaków

    srand(time(NULL));

    cout << "Autor: Kasper Radom 264023" <<endl<< endl;

    int choice = 0;

    do{
        cout<<"Jaki rodzaj testów wybierasz?"<<endl
        <<"\t1. Testy manualne"<<endl
        <<"\t2. Testy automatyczne"<<endl
        <<"\t0. Zakończenie działania programu"<<endl
        <<">>";

        cin>>choice;

        if(choice == 1){
            //inicjowanie pamięci na włączenie testów
            TestyManualne *test = new TestyManualne;

            delete test;
        }else if(choice == 2){
            //inicjowanie pamięci na włączenie testów
            TestyAutomatyczne *test = new TestyAutomatyczne;

            delete test;
        }
    }while(choice != 0);




    //zwolnienie pamięci po objekcie test i wywołanie jego destruktora
//    delete test;

    return 0;
}