#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Expense {
    double amount;
    string date;
    string category;
};

class History {



public:
    vector<Expense> expenses;

    vector<Expense> getExpenses() const {
        return expenses;
    }
    void DodajWydatek(const string& date, const string& category, double amount) {
        expenses.push_back({ amount, date, category });
    }

    void WyborSortowania() {
        cout << "Czy chcesz posortować wydatki? (tak/nie): ";
        string odpowiedz;
        cin >> odpowiedz;

        if (odpowiedz == "tak") {
            cout << "Wybierz metodę sortowania:\n1. Po dacie\n2. Po wielkości\n3. Po kategorii\nWybór: ";
            int wybor;
            cin >> wybor;

            switch (wybor) {
            case 1:
                SortowaniePoDacie();
                break;
            case 2:
                SortowaniePoWielkosci();
                break;
            case 3:
                WyborKategorii();
                break;
            default:
                cout << "Niepoprawny wybór. Wyświetlam niesortowane wydatki.\n";
            }
        }

        WyswietlWydatki();
    }

    void SortowaniePoWielkosci() {
        sort(expenses.begin(), expenses.end(), [](const Expense& a, const Expense& b) {
            return a.amount < b.amount;
            });
    }

    void SortowaniePoDacie() {
        sort(expenses.begin(), expenses.end(), [](const Expense& a, const Expense& b) {
            return a.date < b.date;
            });
    }

    void WyborKategorii() {
        cout << "Podaj kategorię (np. Jedzenie, Transport, Rozrywka): ";
        string chosenCategory;
        cin.ignore();
        getline(cin, chosenCategory);

        expenses.erase(remove_if(expenses.begin(), expenses.end(), [&chosenCategory](const Expense& e) {
            return e.category != chosenCategory;
            }), expenses.end());
    }

    void WyswietlWydatki() {
        for (const Expense& expense : expenses) {
            cout << "Data: " << expense.date << ", Kwota: " << expense.amount << " PLN, Kategoria: " << expense.category << '\n';
        }
    }
};

int main() {
    History historia;

    historia.DodajWydatek("2023-01-01", "Jedzenie", 50.0);
    historia.DodajWydatek("2023-01-02", "Transport", 20.0);
    historia.DodajWydatek("2023-01-03", "Rozrywka", 30.0);

    historia.WyborSortowania();

    return 0;
}
