using namespace std;
#include <iostream>

int main() {
    for (int i = 301; i <= 1200; i += 2) {

        if (i % 400 == 1) {
            cout << "\n";
        }
        else if (i % 100 == 1)
        {
            cout << " *** ";
        }
        else if (i > 301) {
            cout << " ";
        }
        cout << i;
    }

    return 0;
}
