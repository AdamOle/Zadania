using namespace std;
#include <iostream>
#include"Funkcje.h"
#include<cmath>
int main()
{
    double liczba1 = 9;
    double wynik_ln = obliczLogarytmNaturalny(liczba1);
    cout << "Logarytm naturalny z " << liczba1 << " wynosi: " << wynik_ln << endl;


    /// /////////////////////////////////////////////////////

    const int rozmiar = 5;
    double dane[rozmiar] = { 1.0, 2.0, 4.0, 7.0, 11.0 };

    double odchylenie = obliczOdchylenieStandardowe(dane, rozmiar);

    cout << "Odchylenie standardowe wynosi: " << odchylenie << endl;

    /////////////////////////////////////////////////////////
    double liczba = 2.0;

    double wynikExponenty = obliczExponenta(liczba);

    cout << "Wartosc exponenty dla " << liczba << " wynosi: " << wynikExponenty << endl;
    return 0;
}



