/*

Jayden Alonzo-Estrada
Jan. 15, 2025
Menu Class that takes in functions and automatically creates a menu for those functions

*/

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <limits>
#include <map>
#include "testFuncs.h"

// Mapping multiple funcs
    // std::map<std::string, std::function<void()>> functionMap = {
    //     {"Number Input Example", []() {
    //         int result = numbBetweenAB(1, 10, "Enter a number: ", "Invalid input.");
    //         std::cout << "You entered: " << result << '\n';
    //     }},
    //     {"Greet", greet}
    // };

class Menu {
private:
    struct MenuItem {
        std::string description;
        std::function<void()> action;
    };

    std::vector<MenuItem> items;

public:
    // Add a new menu item
    void addItem(const std::string& description, const std::function<void()>& action) {
        items.push_back({description, action});
    }

    // Automatically add multiple functions from a map
    void addFunctionsFromMap(const std::map<std::string, std::function<void()>>& functions) {
        for (const auto& [name, func] : functions) {
            addItem(name, func);
        }
    }

    // Display menu and handle user interaction
    void display() {
        while (true) {
            std::cout << "\nMenu:\n";
            for (size_t i = 0; i < items.size(); ++i) {
                std::cout << i + 1 << ". " << items[i].description << '\n';
            }
            std::cout << "0. Exit\n";
            std::cout << "Choose an option: ";

            int choice;
            std::cin >> choice;

            // Handle invalid input
            if (std::cin.fail()) {
                std::cin.clear(); // Clear the error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                std::cout << "Invalid choice. Please enter a number.\n";
                continue;
            }

            if (choice == 0) {
                std::cout << "Exiting menu...\n";
                break;
            } else if (choice > 0 && choice <= static_cast<int>(items.size())) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                items[choice - 1].action();
            } else {
                std::cout << "Invalid choice. Please try again.\n";
            }
        }
    }
};

// How to use menuClass
    // int main() {
    //     Menu menu;

    //     // Adding single menu items
    //     // menu.addItem("Greet", greet);
    //     menu.addItem("Farewell", farewell);

    //     // Adding a map of funcs
    //     menu.addFunctionsFromMap(functionMap);

    //     // Run the menu
    //     menu.display();

    //     return 0;
    // }



