#include "pch.h"
#include "CppUnitTest.h"
#include"../Kalkulator1/Funkcje.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace kalkulatorTest
{
    TEST_CLASS(kalkulatorTest)
    {
    public:

        TEST_METHOD(ObliczLogarytmNaturalny)
        {

            Assert::IsTrue(obliczLogarytmNaturalny(9) > 0);


            Assert::AreEqual(0.0, obliczLogarytmNaturalny(1));


            Assert::IsTrue(std::isnan(obliczLogarytmNaturalny(-1)));
        }

        TEST_METHOD(ObliczSrednia)
        {
            const int rozmiar = 5;
            double dane[rozmiar] = { 1.0, 2.0, 4.0, 7.0, 11.0 };// 25:5

        
            Assert::AreEqual(5.0, obliczSrednia(dane, rozmiar));
        }

        TEST_METHOD(ObliczOdchylenieStandardowe)
        {
            const int rozmiar = 5;
            double dane[rozmiar] = { 1.0, 2.0, 4.0, 7.0, 11.0 };
            Assert::AreEqual(3.633, obliczOdchylenieStandardowe(dane, rozmiar), 0.0001);
        }

        TEST_METHOD(ObliczExponenta)
        {
            
            Assert::AreEqual(7.3891, obliczExponenta(2), 0.0001);

          // dla 0 exp = 1
            Assert::AreEqual(1.0, obliczExponenta(0));
        }
    };

}