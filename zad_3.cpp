using namespace std;
#include <iostream>


void przeliczOdleglosc(double kilometry, double& mileLadowe, double& mileMorskie) {
    const double MileLadoweNaKilometry = 0.621371;
    const double MileMorskieNaKilometry = 0.539957;

    mileLadowe = kilometry * MileLadoweNaKilometry;
    mileMorskie = kilometry * MileMorskieNaKilometry;
}

int main() {
    double kilometry, mileLadowe, mileMorskie;

    cout << "Podaj odleglosc w kilometrach: ";
    cin >> kilometry;

    przeliczOdleglosc(kilometry, mileLadowe, mileMorskie);

    cout << kilometry << " kilometrow to " << mileLadowe << " mil ladowych." << endl;
    cout << kilometry << " kilometrow to " << mileMorskie << " mil morskich." << endl;

    return 0;
}


