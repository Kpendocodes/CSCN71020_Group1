#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../PolygonChecker/triangleSolver.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestAnalyzeTriangle_Equilateral)
        {
            int a = 5, b = 5, c = 5;
            char* result = analyzeTriangle(a, b, c);
            Assert::AreEqual("", result);
        }

        TEST_METHOD(TestAnalyzeTriangle_Isosceles)
        {
            int a = 5, b = 5, c = 8;
            char* result = analyzeTriangle(a, b, c);
            Assert::AreEqual("", result);
        }

        TEST_METHOD(TestAnalyzeTriangle_Scalene)
        {
            int a = 3, b = 4, c = 5;
            char* result = analyzeTriangle(a, b, c);
            Assert::AreEqual("", result);
        }

        TEST_METHOD(TestAnalyzeTriangle_NotATriangle)
        {
            int a = 1, b = 2, c = 3;
            char* result = analyzeTriangle(a, b, c);
            Assert::AreEqual("", result);
        }

        TEST_METHOD(TestCalculateAngle)
        {
            double side1 = 3, side2 = 3, side3 = 3;
            double angle = calculateAngle(side1, side2, side3);
            Assert::AreEqual(60.00, angle, 0.01);
        }
    };
}
