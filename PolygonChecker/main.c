#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

int main() {
    bool continueProgram = true;

    while (continueProgram) {
        printWelcome();
        int shapeChoice = printShapeMenu();

        switch (shapeChoice) {
        case 1:
            printf_s("Triangle selected.\n");
            int triangleSides[3] = { 0, 0, 0 };
            int* triangleSidesPtr = getTriangleSides(triangleSides);
            char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
            printf_s("%s\n", result);
            break;
        case 2:
            printf_s("Rectangle selected.\n");
            getRectanglePoints();
            break;
        case 0:
            continueProgram = false;
            break;
        default:
            printf_s("Invalid value entered.\n");
            break;
        }
    }
    return 0;
}

void printWelcome() {
    printf_s("\n");
    printf_s(" **********************\n");
    printf_s("** Welcome to **\n");
    printf_s("** Polygon Checker **\n");
    printf_s(" **********************\n");
}

int printShapeMenu() {
    printf_s("1. Triangle\n");
    printf_s("2. Rectangle\n");
    printf_s("0. Exit\n");
    int shapeChoice;
    printf_s("Enter number: ");
    scanf_s("%d", &shapeChoice);
    return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
    printf_s("Enter the three sides of the triangle: ");
    for (int i = 0; i < 3; i++) {
        int sideLength;
        int valid = 0;
        while (valid == 0) {
            if (scanf_s("%d", &sideLength) == 1 && sideLength > 0) {
                triangleSides[i] = sideLength;
                valid = 1;
            }
            else {
                printf_s("Invalid input. Please enter a positive integer: ");
                while (getchar() != '\n');
            }
        }
    }
    return triangleSides;
}

void getRectanglePoints() {
    Point points[4];
    printf_s("Enter the coordinates of four points (x y):\n");
    for (int i = 0; i < 4; i++) {
        printf_s("Point %d: ", i + 1);
        scanf_s("%d %d", &points[i].x, &points[i].y);
    }

    if (isRectangle(points[0], points[1], points[2], points[3])) {
        printf_s("The points form a rectangle.\n");

        double perimeter = calculatePerimeterFromPoints(points[0], points[1], points[2], points[3]);
        double area = calculateAreaFromPoints(points[0], points[1], points[2], points[3]);

        printf_s("Perimeter: %.2lf\n", perimeter);
        printf_s("Area: %.2lf\n", area);
    }
    else {
        printf_s("The points do not form a rectangle.\n");
    }
}
