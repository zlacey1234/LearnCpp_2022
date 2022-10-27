#include <iostream>

int sumTo(int input) {
    int sumVal { 0 };

    for (int count {1}; count <= input; count++) {
        sumVal += count;
    }

    return sumVal;
}

int main() {
    std::cout << "Enter an integer: ";

    int userInput {};
    std::cin >> userInput;

    std::cout << "Summation To " << userInput << " is: " 
        << sumTo(userInput) << '\n';
    
    return 0;
}