#include <iostream>

int GetNumber() {
    std::cout << "Enter a number: ";

    int user_input{ };

    std::cin >> user_input;

    return user_input;
}

bool IsEven(int number) {
    return (number % 2) == 0;
}

void PrintIsEven(int number, bool is_number_even) {
    if (is_number_even) {
        std::cout << number << " is even \n";
    } else {
        std::cout << number << " is odd \n";
    }
}

int main() {
    int user_number{ GetNumber() };

    PrintIsEven(user_number, IsEven(user_number));
    
    return 0;
}