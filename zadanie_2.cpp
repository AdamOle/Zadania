using namespace std;
#include <iostream>

int main() {
    const int arraySize = 10;
    double AA[arraySize];
    int licznik = 0;


    cout << "Wprowadź 10 liczb:\n";
    for (int i = 0; i < arraySize; ++i) {
        cout << "Liczba " << i + 1 << ": ";
        cin >> AA[i];
        if (AA[i] < 0) {
            licznik++;
        }
    }


    double* BB = new double[licznik];
    int index = 0;


    for (int i = 0; i < arraySize; ++i) {
        if (AA[i] < 0) {
            BB[index] = AA[i];
            index++;
        }
    }


    cout << "Ujemne liczby w tablicy BB:\n";
    for (int i = 0; i < licznik; ++i) {
        cout << BB[i] << " ";
    }
    cout << "\nIlosc ujemnych liczb: " << licznik << "\n";
    cout << "Ilosc pominietych liczb: " << (arraySize - licznik) << "\n";


    delete[] BB;

    return 0;
}

