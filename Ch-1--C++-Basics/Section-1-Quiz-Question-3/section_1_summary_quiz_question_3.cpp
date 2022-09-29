#include <iostream>


int main () {
    std::cout << "Enter an integer: ";

    int firstInput{};
    std::cin >> firstInput;

    std::cout << "Enter another integer: ";

    int secondInput{};
    std::cin >> secondInput;

    std::cout << firstInput << " + " << secondInput << " is " << 
        firstInput + secondInput << "\n";
    std::cout << firstInput << " - " << secondInput << " is " << 
        firstInput - secondInput << "\n";

    return 0;
}
