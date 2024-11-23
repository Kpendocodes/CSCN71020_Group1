#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "rectangleSolver.h"

void handleRectangle() {
    double points[4][2];
    printf_s("Enter four points as x y pairs:\n");
    for (int i = 0; i < 4; i++) {
        printf_s("Point %d (x y): ", i + 1);
        if (scanf_s("%lf %lf", &points[i][0], &points[i][1]) != 2 ){
            printf_s("Invalid input. Restarting rectangle process.\n");
            return;
        }
    }

    double distances[4];
    distances[0] = calculateDistance(points[0][0], points[0][1], points[1][0], points[1][1]);
    distances[1] = calculateDistance(points[1][0], points[1][1], points[2][0], points[2][1]);
    distances[2] = calculateDistance(points[2][0], points[2][1], points[3][0], points[3][1]);
    distances[3] = calculateDistance(points[3][0], points[3][1], points[0][0], points[0][1]);

    double perimeter = calculatePerimeter(distances);
    printf_s("Perimeter: %.2f\n", perimeter);

    if (isRectangle(distances)) {
        double area = calculateRectangleArea(distances);
        printf_s("The shape is a rectangle with area: %.2f\n", area);
    }
    else {
        printf_s("The shape is not a rectangle.\n");
    }
}

double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

bool isRectangle(double distances[]) {
    double diagonal1 = calculateDistance(0, 0, distances[0], distances[2]); // Hypothetical diagonal
    double diagonal2 = calculateDistance(0, 0, distances[1], distances[3]);
    return fabs(diagonal1 - diagonal2) < 0.01; // Allow minor float differences
}

double calculatePerimeter(double distances[]) {
    return distances[0] + distances[1] + distances[2] + distances[3];
}

double calculateRectangleArea(double distances[]) {
    return distances[0] * distances[1]; // Assumes user entered rectangle-like order
}
