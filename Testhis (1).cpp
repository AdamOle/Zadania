#include "pch.h"
#include "CppUnitTest.h"
#include "D:\TESTY\historia_wyd\historia_wyd\historia_wyd.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HistoryTest
{
    TEST_CLASS(HistoryTest)
    {
    public:

        TEST_METHOD(DodajWydatek)
        {
            History historia;

            // dodajemy losowy  wydatek
            historia.DodajWydatek("2023-01-04", "Jedzenie", 60.0);

            // teraz sprawdzamy  czy wydatek został dodany poprawnie
            vector<Expense> expenses = historia.getExpenses();
            Assert::AreEqual("2023-01-04", expenses[0].date.c_str()); // Oczekiwana data
            Assert::AreEqual("Jedzenie", expenses[0].category.c_str()); // Oczekiwana kategoria
            Assert::AreEqual(60.0, expenses[0].amount); // Oczekiwana kwota
        }

        TEST_METHOD(SortowaniePoDacieTest)
        {
            History historia;

            // wydatki w losowej kolejności
            historia.DodajWydatek("2023-01-04", "Jedzenie", 60.0);
            historia.DodajWydatek("2023-01-02", "Transport", 20.0);
            historia.DodajWydatek("2023-01-03", "Rozrywka", 30.0);

            // sortowanie po dacie
            historia.SortowaniePoDacie();

            // Sprawdzamy czy wydatki są posortowane poprawnie
            vector<Expense> expenses = historia.getExpenses();
            Assert::AreEqual("2023-01-02", expenses[0].date.c_str());
            Assert::AreEqual("2023-01-03", expenses[1].date.c_str());
            Assert::AreEqual("2023-01-04", expenses[2].date.c_str());
        }
    };
}
