/**
 * @file UnitTest.cpp
 * @brief Модульные тесты для проверки корректности алгоритмов.
 */

#include "CppUnitTest.h"
#include "Piquet.h"
#include "Peregon.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
    TEST_CLASS(RailwayTests)
    {
    public:
        /**
         * @brief Проверка корректности создания пикета из дистанции в метрах.
         */
        TEST_METHOD(Piquet_ConstructorDouble)
        {
            Piquet p(1250.5); // 1250.5 метров это ПК 12+50.5
            Assert::AreEqual(12, p.number);
            Assert::AreEqual(50.5, p.shift, 0.001);
            Assert::IsTrue(p.isStandard);
        }

        /**
         * @brief Проверка сериализации стандартного (положительного) пикета.
         */
        TEST_METHOD(Piquet_ToString_Positive)
        {
            Piquet p(12, 28.37, 100.0);
            std::string expected = "ПК 12+28.37";
            Assert::AreEqual(expected, p.toString());
        }

        /**
         * @brief Проверка форматирования отрицательного пикета (добавление нуля).
         */
        TEST_METHOD(Piquet_ToString_Negative)
        {
            Piquet p(-12, 28.37, 100.0);
            std::string expected = "ПК 012+28.37";
            Assert::AreEqual(expected, p.toString());
        }

        /**
         * @brief Проверка расчета длины перегона без немерных пикетов.
         */
        TEST_METHOD(Peregon_Length_Standard)
        {
            Peregon p(Piquet(0, 0.0, 100.0), Piquet(5, 0.0, 100.0));
            Assert::AreEqual(500.0, p.calculateLength(), 0.001);
        }

        /**
         * @brief Проверка расчета длины перегона с учетом укороченного пикета.
         */
        TEST_METHOD(Peregon_Length_WithBadPiquets)
        {
            Peregon p(Piquet(0, 0.0, 100.0), Piquet(10, 0.0, 100.0));
            p.addPiquet(Piquet(5, 0.0, 80.0)); 
            Assert::AreEqual(980.0, p.calculateLength(), 0.001);
        }
    };
}