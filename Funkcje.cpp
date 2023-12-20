#include "Funkcje.h"
#include <cmath>
#include <iostream>

using namespace std;


double obliczLogarytmNaturalny(double x) {
    return log(x);
}


double obliczSrednia(const double dane[], int rozmiar) {
    double suma = 0.0;
    for (int i = 0; i < rozmiar; ++i) {
        suma += dane[i];
    }
    return suma / rozmiar;
}


double obliczOdchylenieStandardowe(const double dane[], int rozmiar) {
    if (rozmiar <= 1) {
        cout << "Za ma³o danych do obliczenia odchylenia standardowego." << endl;
        return 0.0;
    }

    double srednia = obliczSrednia(dane, rozmiar);
    double sumaKwadratowRoznic = 0.0;

    for (int i = 0; i < rozmiar; ++i) {
        sumaKwadratowRoznic += pow(dane[i] - srednia, 2);
    }

    return sqrt(sumaKwadratowRoznic / (rozmiar - 1));
}




double obliczExponenta(double x) {
    return exp(x);
}










