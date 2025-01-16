#include "menuClass.h"

std::map<std::string, std::function<void()>> functionMap = {
    {"Number Input Example", []() {
        int result = numbBetweenAB(1, 10, "", "");
        std::cout << "You entered: " << result << '\n';
    }},
    {"Greet", greet}
};

int main() {
    Menu menu;

    // Adding single menu items
    // menu.addItem("Greet", greet);
    menu.addItem("Farewell", farewell);

    // Adding a map of funcs
    menu.addFunctionsFromMap(functionMap);

    // Run the menu
    menu.display();

    return 0;
}