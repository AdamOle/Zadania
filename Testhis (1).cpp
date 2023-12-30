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

            // Dodaj wydatek
            historia.DodajWydatek("2023-01-04", "Jedzenie", 60.0);

            // Sprawdü, czy wydatek zosta≥ dodany poprawnie
            vector<Expense> expenses = historia.getExpenses();
            Assert::AreEqual("2023-01-04", expenses[0].date.c_str()); // Oczekiwana data
            Assert::AreEqual("Jedzenie", expenses[0].category.c_str()); // Oczekiwana kategoria
            Assert::AreEqual(60.0, expenses[0].amount); // Oczekiwana kwota
        }

        TEST_METHOD(SortowaniePoDacieTest)
        {
            History historia;

            // Dodaj wydatki w losowej kolejnoúci
            historia.DodajWydatek("2023-01-04", "Jedzenie", 60.0);
            historia.DodajWydatek("2023-01-02", "Transport", 20.0);
            historia.DodajWydatek("2023-01-03", "Rozrywka", 30.0);

            // Posortuj wydatki po dacie
            historia.SortowaniePoDacie();

            // Sprawdü, czy wydatki sπ posortowane poprawnie
            vector<Expense> expenses = historia.getExpenses();
            Assert::AreEqual("2023-01-02", expenses[0].date.c_str());
            Assert::AreEqual("2023-01-03", expenses[1].date.c_str());
            Assert::AreEqual("2023-01-04", expenses[2].date.c_str());
        }
    };
}
