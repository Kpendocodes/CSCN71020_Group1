#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "triangleSolver.h"

#define PI		3.14

double calculateAngle(double side1, double side2, double side3) {
	double cosAngle = (side1 * side1 + side2 * side2 - side3 * side3) / (2 * side1 * side2);
	if (cosAngle > 1.0) cosAngle = 1.0;
	if (cosAngle < -1.0) cosAngle = -1.0;
	return acos(cosAngle) * 180.0 / PI;
}

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		double angleA = calculateAngle(side2, side3, side1);
		double angleB = calculateAngle(side1, side3, side2);
		double angleC = calculateAngle(side1, side2, side3);

		printf_s("This is a Equilateral triangle with angles: \n");
		printf_s("Angle A: %.2f degrees\n", angleA);
		printf_s("Angle B: %.2f degrees\n", angleB);
		printf_s("Angle C: %.2f degrees\n", angleC);
		/*result = "Equilateral triangle";*/
	}
	else if (((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2)) ||
		(side2 == side3 && side1 != side2))
	{
		double angleA = calculateAngle(side2, side3, side1);
		double angleB = calculateAngle(side1, side3, side2);
		double angleC = calculateAngle(side1, side2, side3);

		printf_s("This is an isosceles triangle with angles: \n");
		printf_s("Angle A: %.2f degrees\n", angleA);
		printf_s("Angle B: %.2f degrees\n", angleB);
		printf_s("Angle C: %.2f degrees\n", angleC);
		/*result = "Isosceles triangle";*/
	}
	else {
		double angleA = calculateAngle(side2, side3, side1);
		double angleB = calculateAngle(side1, side3, side2);
		double angleC = calculateAngle(side1, side2, side3);

		printf_s("This is a scalene triangle with angles: \n");
		printf_s("Angle A: %.2f degrees\n", angleA);
		printf_s("Angle B: %.2f degrees\n", angleB);
		printf_s("Angle C: %.2f degrees\n", angleC);
		/*return "Scalene triangle";*/
	}

	return result;
}