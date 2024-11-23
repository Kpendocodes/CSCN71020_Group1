#include "pch.h"
#include "CppUnitTest.h"
#include "triangleSolver.h"  // Include your header file with the functions to test

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(UnitTests)
    {
    public:

        TEST_METHOD(TestValidTriangle)
        {
            // Arrange
            int a = 3, b = 4, c = 5; // Example sides of a triangle
            bool expected = true;

            // Act
            bool result = isValidTriangle(a, b, c); // Assuming this function exists

            // Assert
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestInvalidTriangle)
        {
            // Arrange
            int a = 1, b = 2, c = 3; // These sides do not form a triangle
            bool expected = false;

            // Act
            bool result = isValidTriangle(a, b, c);

            // Assert
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestTriangleInequality)
        {
            // Arrange
            int a = 5, b = 10, c = 20; // These sides do not satisfy the triangle inequality
            bool expected = false;

            // Act
            bool result = isValidTriangle(a, b, c);

            // Assert
            Assert::AreEqual(expected, result);
        }
    };
}