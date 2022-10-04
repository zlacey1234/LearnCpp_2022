#include <iostream>

int main() {
    std::cout << "Enter a positive number: ";
    
    int number{};
    std::cin >> number;

    if (number < 0) {
        std::cout << "Negative number entered. Making positive.\n";
        number = -number;
    }

    std::cout << "You entered: " << number << '\n';

    return 0;
}