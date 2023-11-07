using namespace std;
#include <iostream>
#include <string>


struct Produkt {
    string nazwa;
    double cena;
};

int main() {
    const int iloscProduktow = 10;
    Produkt produkty[iloscProduktow];

    for (int i = 0; i < iloscProduktow; i++) {
        cout << "Podaj nazwę produktu " << (i + 1) << ": ";
        cin >> produkty[i].nazwa;
        cout << "Podaj cenę produktu " << (i + 1) << ": ";
        cin >> produkty[i].cena;
    }

    //  (sortowanie bąbelkowe)
    for (int i = 0; i < iloscProduktow - 1; i++) {
        for (int j = 0; j < iloscProduktow - 1 - i; j++) {
            if (produkty[j].cena < produkty[j + 1].cena) {
                
                Produkt temp = produkty[j];
                produkty[j] = produkty[j + 1];
                produkty[j + 1] = temp;
            }
        }
    }

    
    cout <<endl<<endl<< "Produkty od najdroższych do najtańszych:\n";
    for (int i = 0; i < iloscProduktow; i++) {
        cout<< "Nazwa: " << produkty[i].nazwa << ", Cena: " << produkty[i].cena << endl;
    }

    return 0;
}

