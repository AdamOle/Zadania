using namespace std;

#include <iostream>

struct Produkt
{
    string nazwa;
    double cena;
};
int main()
{
    
    const int iloscProduktow =10;
    Produkt produkty[iloscProduktow];
    for (int i = 0; i < iloscProduktow; i++)
    {
        cout << "Podaj produkt nazwa : ";
        cin >> produkty[i].nazwa;
        cout<< endl << "cena : ";
        cin >> produkty[i].cena;

    }

    for (int i = 0; i < iloscProduktow; i++)
    {

    }
}

