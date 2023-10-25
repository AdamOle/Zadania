using namespace std;

#include <iostream>

int ZliczLiczbyujemne(int AA[10])
{
    int ile = 0;
    int pominiete = 0;
    int n = 0;
    int* BB = new int[n];
    for (int i = 0; i < 10; i++)
    {

        if (AA[i] < 0)
        {
            cout << endl << "liczba ujemne:";
            ile++;
            BB[n] = AA[i];

            cout << BB[n];
        }
        else
        {
            pominiete++;
        }




    }
    cout << endl << "Liczb ujemnych: " << ile;
    cout << endl << "Pominietych: " << pominiete;
    return BB[n];
}

int main()
{
    int AA[10];
    for (int i = 0; i < 10; i++)
    {

        cout << endl << "Wprowadz liczbe :";
        cin >> AA[i];
    }
    ZliczLiczbyujemne(AA);

}

