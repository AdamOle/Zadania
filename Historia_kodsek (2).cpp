#include <iostream>
#include <string>

using namespace std;
const int MAX_WYDATKI = 10;

struct Wydatek {
    string kategoria;
    double kwota;
    string data;
};

Wydatek wydatki[MAX_WYDATKI];
int liczbaWydatkow = 0;

void pobierzHistorie() {
    // Przykładowe dane, w rzeczywistym przypadku tutaj byłoby pobieranie danych z bazy danych
    wydatki[0] = { "Jedzenie", 150.0, "2024-01-05" };
    wydatki[1] = { "Transport", 50.0, "2024-01-04" };
    wydatki[2] = { "Rozrywka", 200.0, "2024-01-03" };
    liczbaWydatkow = 3;
}

void BrakWprowadzonychWydatkow() {
    cout << "Brak wprowadzonych wydatków." << endl;
}

void sortujPoKategorii() {
    for (int i = 0; i < liczbaWydatkow - 1; i++) {
        for (int j = 0; j < liczbaWydatkow - i - 1; j++) {
            if (wydatki[j].kategoria > wydatki[j + 1].kategoria) {
                Wydatek temp = wydatki[j];
                wydatki[j] = wydatki[j + 1];
                wydatki[j + 1] = temp;
            }
        }
    }
}

void sortujPoKwocie() {
    for (int i = 0; i < liczbaWydatkow - 1; i++) {
        for (int j = 0; j < liczbaWydatkow - i - 1; j++) {
            if (wydatki[j].kwota > wydatki[j + 1].kwota) {
                Wydatek temp = wydatki[j];
                wydatki[j] = wydatki[j + 1];
                wydatki[j + 1] = temp;
            }
        }
    }
}

void sortujPoDacie() {
    for (int i = 0; i < liczbaWydatkow - 1; i++) {
        for (int j = 0; j < liczbaWydatkow - i - 1; j++) {
            if (wydatki[j].data > wydatki[j + 1].data) {
                Wydatek temp = wydatki[j];
                wydatki[j] = wydatki[j + 1];
                wydatki[j + 1] = temp;
            }
        }
    }
}

void wyswietlWydatki() {
    for (int i = 0; i < liczbaWydatkow; i++) {
        cout << "Kategoria: " << wydatki[i].kategoria
            << ", Kwota: " << wydatki[i].kwota
            << ", Data: " << wydatki[i].data << endl;
    }
}

void wyswietlWydatkiPoKategorii(const string& kategoria) {
    bool znaleziono = false;
    for (int i = 0; i < liczbaWydatkow; i++) {
        if (wydatki[i].kategoria == kategoria) {
            cout << "Kategoria: " << wydatki[i].kategoria
                << ", Kwota: " << wydatki[i].kwota
                << ", Data: " << wydatki[i].data << endl;
            znaleziono = true;
        }
    }
    if (!znaleziono) {
        cout << "Nie znaleziono wydatków w kategorii " << kategoria << ".\n";
    }
}

int main() {
    pobierzHistorie();
    
    if (liczbaWydatkow == 0) {
        BrakWprowadzonychWydatkow();
        return 0;
    }
    char wybor;
    cout << "Czy chcesz posortowac wydatki? (y/n): ";
    cin >> wybor;

    if (wybor == 'y' || wybor == 'Y') {
        cout << "Wybierz rodzaj sortowania: \n"
            << "1. Kategoria\n"
            << "2. Kwota\n"
            << "3. Data\n"
            << "Wybor: ";
        cin >> wybor;

        switch (wybor) {
        case '1':
            sortujPoKategorii();
            {
                string wybranaKategoria;
                cout << "Podaj nazwe kategorii: ";
                cin >> wybranaKategoria;
                wyswietlWydatkiPoKategorii(wybranaKategoria);
            }
            break;
        case '2':
            sortujPoKwocie();
            wyswietlWydatki();
            break;
        case '3':
            sortujPoDacie();
            wyswietlWydatki();
            break;
        default:
            cout << "Niepoprawny wybor." << endl;
            return 1;
        }
    }
    else {
        wyswietlWydatki();
    }

    return 0;
}