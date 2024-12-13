#pragma once

typedef struct {
    int x;
    int y;
}Point;

double calculateDistance(Point p1, Point p2);
bool isRectangle(Point p1, Point p2, Point p3, Point p4);
double calculatePerimeterFromPoints(Point p1, Point p2, Point p3, Point p4);
double calculateAreaFromPoints(Point p1, Point p2, Point p3, Point p4);