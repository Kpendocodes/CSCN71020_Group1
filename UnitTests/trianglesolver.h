#pragma once

// Function to check if three sides can form a valid triangle
bool isValidTriangle(int a, int b, int c) {
    // A triangle is valid if the sum of any two sides is greater than the third side
    return (a + b > c) && (a + c > b) && (b + c > a);
}
