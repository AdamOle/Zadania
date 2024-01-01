#include "pch.h"
#include "CppUnitTest.h"
#include "D:\TESTY\mediana\mediana\mediana.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MedianTest
{
    TEST_CLASS(MedianTest)
    {
    public:
        TEST_METHOD(TestObliczMedianeNieparzysta)
        {
            int liczby[] = { 3, 1, 4 };
            int rozmiar = sizeof(liczby) / sizeof(liczby[0]);
            double expectedMedian = 3.0;

            double result = obliczMediane(liczby, rozmiar);
            Assert::AreEqual(expectedMedian, result);
        }

        TEST_METHOD(TestObliczMedianeParzysta)
        {
            int liczby[] = { 1, 2, 3, 4 };
            int rozmiar = sizeof(liczby) / sizeof(liczby[0]);
            double expectedMedian = 2.5;

            double result = obliczMediane(liczby, rozmiar);
            Assert::AreEqual(expectedMedian, result);
        }

        TEST_METHOD(TestObliczMedianeJednoElementowa)
        {
            int liczby[] = { 5 };
            int rozmiar = sizeof(liczby) / sizeof(liczby[0]);
            double expectedMedian = 5.0;

            double result = obliczMediane(liczby, rozmiar);
            Assert::AreEqual(expectedMedian, result);
        }

       
       
    };
}
