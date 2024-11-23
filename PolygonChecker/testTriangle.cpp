#include "pch.h"  // Add this line
#include <iostream>
#include <cassert>
#include <cstring>
#include "main.h"
#include "triangleSolver.h"
#include "testTrangle.h"

void testPrintWelcome() {
    std::cout << "Testing printWelcome..." << std::endl;
    printWelcome(); // Check if it runs without crashing
}

int testPrintShapeMenu(int input) {
    std::cout << "Testing printShapeMenu..." << std::endl;
    return input; // Simulate user input
}

void testGetTriangleSides() {
    std::cout << "Testing getTriangleSides..." << std::endl;
    int sides[3] = { 3, 4, 5 }; // Example sides
    int* result = getTriangleSides(sides);
    assert(result[0] == 3);
    assert(result[1] == 4);
    assert(result[2] == 5);
}

void testAnalyzeTriangle() {
    std::cout << "Testing analyzeTriangle..." << std::endl;
    assert(strcmp(analyzeTriangle(3, 4, 5), "Scalene triangle") == 0);
    assert(strcmp(analyzeTriangle(3, 3, 3), "Equilateral triangle") == 0);
    assert(strcmp(analyzeTriangle(3, 3, 5), "Isosceles triangle") == 0);
    assert(strcmp(analyzeTriangle(0, 4, 5), "Not a triangle") == 0);
    assert(strcmp(analyzeTriangle(-1, 4, 5), "Not a triangle") == 0);
}