

#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\aolec\Downloads\Historia_kodsek (1).cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WydatkiTest
{
    TEST_CLASS(WydatkiTest)
    {
    public:
       
        int liczWydatkiWKategorii(const string& kategoria) {
            int liczba = 0;
            for (int i = 0; i < liczbaWydatkow; i++) {
                if (wydatki[i].kategoria == kategoria) {
                    liczba++;
                }
            }
            return liczba;
        }


        void DodajWydatekTestowy(string data, string kategoria, double kwota) {
            if (liczbaWydatkow < MAX_WYDATKI) {
                wydatki[liczbaWydatkow++] = { kategoria, kwota, data };
            }
        }

        TEST_METHOD(SortujPoKategoriiTest) {
            DodajWydatekTestowy("2024-01-05", "Jedzenie", 150.0);
            DodajWydatekTestowy("2024-01-04", "Transport", 50.0);
            DodajWydatekTestowy("2024-01-03", "Rozrywka", 200.0);

            sortujPoKategorii();

            // Sprawdzam czy wydatki s¹ posortowane poprawnie
            Assert::IsTrue(wydatki[0].kategoria <= wydatki[1].kategoria);
            Assert::IsTrue(wydatki[1].kategoria <= wydatki[2].kategoria);
        }

        TEST_METHOD(SortujPoKwocieTest) {
            DodajWydatekTestowy("2024-01-05", "Jedzenie", 150.0);
            DodajWydatekTestowy("2024-01-04", "Transport", 50.0);
            DodajWydatekTestowy("2024-01-03", "Rozrywka", 200.0);

            sortujPoKwocie();

            // Sprawdzam czy kwoty s¹ posortowane poprawnie
            Assert::IsTrue(wydatki[0].kwota <= wydatki[1].kwota);
            Assert::IsTrue(wydatki[1].kwota <= wydatki[2].kwota);
        }

        TEST_METHOD(SortujPoDacieTest) {
            DodajWydatekTestowy("2024-01-05", "Jedzenie", 150.0);
            DodajWydatekTestowy("2024-01-04", "Transport", 50.0);
            DodajWydatekTestowy("2024-01-03", "Rozrywka", 200.0);

            sortujPoDacie();

            // Sprawdzam czy daty s¹ posortowane poprawnie
            Assert::IsTrue(wydatki[0].data <= wydatki[1].data);
            Assert::IsTrue(wydatki[1].data <= wydatki[2].data);
        }

        TEST_METHOD(FiltrujWydatkiPoKategoriiTest) {
            DodajWydatekTestowy("2024-01-05", "Jedzenie", 150.0);
            DodajWydatekTestowy("2024-01-04", "Transport", 50.0);
            DodajWydatekTestowy("2024-01-03", "Jedzenie", 200.0);

            int liczbaWydatkowJedzenie = liczWydatkiWKategorii("Jedzenie");

            // Sprawdzam czy liczba zwróconych wydatków jest zgodna z oczekiwaniami
            Assert::AreEqual(2, liczbaWydatkowJedzenie);
        }

        TEST_METHOD(DodajWydatekTest) {
            int poczatkowaLiczbaWydatkow = liczbaWydatkow;
            DodajWydatekTestowy("2024-01-06", "Ubrania", 100.0);

            Assert::AreEqual(poczatkowaLiczbaWydatkow + 1, liczbaWydatkow);
            Assert::AreEqual(string("Ubrania"), wydatki[liczbaWydatkow - 1].kategoria);
            Assert::AreEqual(100.0, wydatki[liczbaWydatkow - 1].kwota);
            Assert::AreEqual(string("2024-01-06"), wydatki[liczbaWydatkow - 1].data);
        }
        
        TEST_METHOD(PrzekroczenieMaxWydatkowTest) {
            for (int i = liczbaWydatkow; i < MAX_WYDATKI; i++) {
                DodajWydatekTestowy("2024-01-07", "Inne", 10.0);
            }

            // Próba dodania kolejnego wydatku
            DodajWydatekTestowy("2024-01-08", "Inne", 20.0);

            Assert::AreEqual(MAX_WYDATKI, liczbaWydatkow);  // Liczba wydatków nie powinna przekroczyæ maksimum wydatkow
        }



    };
}
