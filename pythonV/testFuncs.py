# Test functions
def greet():
    print("Hello, welcome to the menu!")

def farewell():
    print("Goodbye, thanks for using the menu!")

def numb_between_ab(A, B, line="", errorline=""):
    """
    Prompt the user to enter a number between A and B.
    :param A: Minimum number (inclusive).
    :param B: Maximum number (inclusive).
    :param line: Prompt message.
    :param errorline: Error message.
    :return: Valid number between A and B.
    """
    prompt_line = line or f"Enter a number between {A} and {B} (inclusive): "
    error_line = errorline or f"Number not between {A} and {B}"

    while True:
        try:
            tmp = int(input(prompt_line))
            if A <= tmp <= B:
                return tmp
            else:
                raise ValueError
        except ValueError:
            print(error_line)
