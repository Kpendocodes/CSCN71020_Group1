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
            handleRectangle();
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
