#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "rectangleSolver.h"

double calculateDistance(Point p1, Point p2) {
    return sqrt((double)(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)));
}

bool isRectangle(Point p1, Point p2, Point p3, Point p4) {
    double d1 = calculateDistance(p1, p2);
    double d2 = calculateDistance(p2, p3);
    double d3 = calculateDistance(p3, p4);
    double d4 = calculateDistance(p4, p1);
    double diag1 = calculateDistance(p1, p3);
    double diag2 = calculateDistance(p2, p4);

    return (d1 == d3 && d2 == d4 && diag1 == diag2);
}

double calculatePerimeterFromPoints(Point p1, Point p2, Point p3, Point p4) {
    double d1 = calculateDistance(p1, p2);
    double d2 = calculateDistance(p2, p3);
    return 2 * (d1 + d2);
}

double calculateAreaFromPoints(Point p1, Point p2, Point p3, Point p4) {
    double d1 = calculateDistance(p1, p2);
    double d2 = calculateDistance(p2, p3);
    return d1 * d2;
}

