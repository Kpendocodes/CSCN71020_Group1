#include <iostream>
#include "main.h"
#include "triangleSolver.h"


#define _CRT_SECURE_NO_WARNINGS
// Function implementations
void printWelcome() {
    std::cout << "\n **********************\n";
    std::cout << "**     Welcome to     **\n";
    std::cout << "**   Polygon Checker  **\n";
    std::cout << " **********************\n";
}

int* getTriangleSides(int* triangleSides) {
    std::cout << "Enter the three sides of the triangle: ";
    for (int i = 0; i < 3; i++) {
        std::cin >> triangleSides[i];
    }
    return triangleSides;
}