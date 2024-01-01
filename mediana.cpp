#include <iostream>
#include "mediana.h"



void posortujTablice(int tablica[], int rozmiar) {
    for (int i = 0; i < rozmiar - 1; i++) {
        for (int j = 0; j < rozmiar - i - 1; j++) {
            if (tablica[j] > tablica[j + 1]) {
                
                int tymczasowa = tablica[j];
                tablica[j] = tablica[j + 1];
                tablica[j + 1] = tymczasowa;
            }
        }
    }
}

double obliczMediane(int tablica[], int rozmiar) {
    posortujTablice(tablica, rozmiar);

    if (rozmiar % 2 == 0) {
     
        return (tablica[rozmiar / 2 - 1] + tablica[rozmiar / 2]) / 2.0;
    }
    else {
      
        return tablica[rozmiar / 2];
    }
}

int main() {
    int liczby[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
    int rozmiar = sizeof(liczby) / sizeof(liczby[0]);

    std::cout << "Mediana wynosi: " << obliczMediane(liczby, rozmiar) << std::endl;
    return 0;
}
