# Jayden Alonzo-Estrada
# Jan. 15, 2025
# Menu Class that takes in functions and automatically creates a menu for those functions

class Menu:
    class MenuItem:
        def __init__(self, description, action):
            self.description = description
            self.action = action

    def __init__(self):
        self.items = []

    def add_item(self, description, action):
        """
        Add a new menu item.
        :param description: Description of the menu item.
        :param action: A callable representing the menu action.
        """
        self.items.append(Menu.MenuItem(description, action))

    def add_functions_from_dict(self, functions):
        """
        Add multiple functions from a dictionary.
        :param functions: A dictionary with descriptions as keys and callables as values.
        """
        for name, func in functions.items():
            self.add_item(name, func)

    def display(self):
        """
        Display the menu and handle user interaction.
        """
        while True:
            print("\nMenu:")
            for i, item in enumerate(self.items, start=1):
                print(f"{i}. {item.description}")
            print("0. Exit")

            try:
                choice = int(input("Choose an option: "))
                if choice == 0:
                    print("Exiting menu...")
                    break
                elif 1 <= choice <= len(self.items):
                    self.items[choice - 1].action()
                else:
                    print("Invalid choice. Please try again.")
            except ValueError:
                print("Invalid input. Please enter a number.")

# How to use Menu
# if __name__ == "__main__":
#     menu = Menu()
#     menu.add_item("Greet", greet)
#     menu.add_item("Farewell", farewell)
#     function_dict = {
#         "Number Input Example": lambda: print(numb_between_ab(1, 10, "Enter a number: ", "Invalid input.")),
#         "Greet": greet
#     }
#     menu.add_functions_from_dict(function_dict)
#     menu.display()
