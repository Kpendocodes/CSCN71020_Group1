#include "pch.h"
#include "CppUnitTest.h"
#include "../PolygonChecker/triangleSolver.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestValidTriangle)
        {
            int a = 3, b = 4, c = 5;
            bool expected = true;

            bool result = isValidTriangle(a, b, c);

            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestInvalidTriangle)
        {
            int a = 1, b = 2, c = 3; 
            bool expected = false;

            bool result = isValidTriangle(a, b, c);

            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestTriangleInequality)
        {
            int a = 5, b = 10, c = 20;
            bool expected = false;

            bool result = isValidTriangle(a, b, c);

            Assert::AreEqual(expected, result);
        }
    };
}
