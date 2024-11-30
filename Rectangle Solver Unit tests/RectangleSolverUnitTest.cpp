#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../PolygonChecker/rectangleSolver.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleSolverUnittests
{
	TEST_CLASS(RectangleSolverUnittests)
	{
	public:

		TEST_METHOD(TestCalculateDistance)
		{
			Point p1 = { 0, 0 };
			Point p2 = { 3, 4 };
			double dist = calculateDistance(p1, p2);
			Assert::AreEqual(5.0, dist, 0.01);
		}

		TEST_METHOD(TestIsRectangle)
		{
			Point p1 = { 0, 0 };
			Point p2 = { 3, 0 };
			Point p3 = { 3, 4 };
			Point p4 = { 0, 4 };

			Assert::IsTrue(isRectangle(p1, p2, p3, p4));

			Point nonRect1 = { 0, 0 };
			Point nonRect2 = { 2, 0 };
			Point nonRect3 = { 3, 3 };
			Point nonRect4 = { 0, 3 };

			Assert::IsFalse(isRectangle(nonRect1, nonRect2, nonRect3, nonRect4));
		}

		TEST_METHOD(TestCalculatePerimeter)
		{
			Point p1 = { 0, 0 };
			Point p2 = { 3, 0 };
			Point p3 = { 3, 4 };
			Point p4 = { 0, 4 };

			double perimeter = calculatePerimeterFromPoints(p1, p2, p3, p4);
			Assert::AreEqual(14.0, perimeter, 0.01);
		}

		TEST_METHOD(TestCalculateRectangleArea)
		{
			Point p1 = { 0, 0 };
			Point p2 = { 3, 0 };
			Point p3 = { 3, 4 };
			Point p4 = { 0, 4 };

			double area = calculateAreaFromPoints(p1, p2, p3, p4);
			Assert::AreEqual(12.0, area, 0.01);
		}
	};
}
