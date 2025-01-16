#pragma once

#include <iostream>
#include <string>

// Test functions
void greet() {
    std::cout << "Hello, welcome to the menu!\n";
}

void farewell() {
    std::cout << "Goodbye, thanks for using the menu!\n";
}

// Function to prompt the user to enter a number between A and B
int numbBetweenAB(int A, int B, const std::string& line = "", const std::string& errorline = "") {
    int tmp = 0;
    int state = 0;

    // Default messages if not provided
    std::string promptLine = line.empty() ? 
        "Enter a number between " + std::to_string(A) + " and " + std::to_string(B) + " (inclusive): " 
        : line;
    std::string errorLine = errorline.empty() ? 
        "Number not between " + std::to_string(A) + " and " + std::to_string(B) + '\n' 
        : errorline;

    // Loop until a valid input is entered
    while (state == 0) {
        try {
            std::cout << promptLine;
            std::string tmpStr;
            std::getline(std::cin, tmpStr);
            tmp = std::stoi(tmpStr); // Convert string to integer

            if (tmp < A || tmp > B) {
                throw std::out_of_range("Input out of range");
            }
            state = 1; // Valid input, exit loop
        } catch (...) {
            std::cout << errorLine;
        }
    }
    return tmp;
}
