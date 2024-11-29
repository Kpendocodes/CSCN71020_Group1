#include "pch.h"
#include "CppUnitTest.h"
#include "rectangleSolver.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleSolverUnittests
{
	TEST_CLASS(RectangleSolverUnittests)
	{
	public:

		TEST_METHOD(TestCalculateDistance)
		{
			double dist = calculateDistance(0, 0, 3, 4);
			Assert::AreEqual(5.0, dist, 0.01);
		}

		TEST_METHOD(TestIsRectangle)
		{
			double distances[4] = { 3, 4, 3, 4 };
			Assert::IsTrue(isRectangle(distances));

			double nonRectDistances[4] = { 3, 4, 5, 6 };
			Assert::IsFalse(isRectangle(nonRectDistances));
		}

		TEST_METHOD(TestCalculatePerimeter)
		{
			double distances[4] = { 3, 4, 3, 4 };
			double perimeter = calculatePerimeter(distances);
			Assert::AreEqual(14.0, perimeter, 0.01);
		}

		TEST_METHOD(TestCalculateRectangleArea)
		{
			double distances[4] = { 3, 4, 3, 4 };
			double area = calculateRectangleArea(distances);
			Assert::AreEqual(12.0, area, 0.01);
		}
	};
}