#include <iostream>
using namespace std;
struct Expense {
    string category;
    double amount;
    string date;
};

bool compareByCategory(const Expense& a, const Expense& b) {
    return a.category < b.category;
}

bool compareByDate(const Expense& a, const Expense& b) {
    return a.date < b.date;
}

void bubbleSort(Expense* arr, int n, bool (*compareFunction)(const Expense&, const Expense&)) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (!compareFunction(arr[j], arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void displayExpenses(Expense* arr, int n, const string& selectedCategory) {
    cout << "-------------------------\n";
    cout << " Kategoria  |  Kwota  |  Data\n";
    cout << "-------------------------\n";

    for (int i = 0; i < n; ++i) {
        if (selectedCategory.empty() || arr[i].category == selectedCategory) {
            cout << " " << arr[i].category << "  |  " << arr[i].amount << "  |  " << arr[i].date << "\n";
        }
    }
}

int main() {
    const int maxExpenses = 100;
    Expense* expenses = new Expense[maxExpenses];
  
    expenses[0] = { "Jedzenie", 50.0, "2023-11-01" };
    expenses[1] = { "Transport", 30.0, "2023-11-02" };
    expenses[2] = { "Rozrywka", 20.0, "2023-11-03" };
    
    int numberOfExpenses = 3;

   

    if (numberOfExpenses > 0) {
       
        bool sortByCategory = false;
        cout << "Czy chcesz posortowac wydatki wedlug kategorii? (T/N): ";
        char sortChoice;
        cin >> sortChoice;
        if (sortChoice == 'T' || sortChoice == 't') {
            sortByCategory = true;
            bubbleSort(expenses, numberOfExpenses, compareByCategory);

            string selectedCategory;
            cout << "Podaj kategorie, dla ktorej chcesz zobaczyc historie wydatkow: ";
            cin >> selectedCategory;

            cout << "Historia Wydatkow dla kategorii " << selectedCategory << ":\n";
            displayExpenses(expenses, numberOfExpenses, selectedCategory);
        }
        else {
            bubbleSort(expenses, numberOfExpenses, compareByDate);

            cout << "Historia Wydatkow posortowana chronologicznie:\n";
            displayExpenses(expenses, numberOfExpenses, "");
        }
    }
    else {
        cout << "Brak dostępnych wydatków do wyświetlenia.\n";
    }


    delete[] expenses;

    return 0;
}
