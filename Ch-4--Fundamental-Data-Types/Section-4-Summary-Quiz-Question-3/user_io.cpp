#include "user_io.h"
#include <iostream>

double ReadNumber() {
    std::cout << "Enter a double value: ";

    double user_input { };
    std::cin >> user_input;

    return user_input;
}

char GetArithmeticSymbol() {
    std::cout << "Enter one of the following: +, -, *, or /: ";

    char arithmetic_symbol { };
    std::cin >> arithmetic_symbol;
    
    return arithmetic_symbol;
} 

void PrintArithmeticExpression(
    double first_number, double second_number, char arithmetic_symbol) {
        double arithmetic_solution { };

        if (arithmetic_symbol == '+') {
            arithmetic_solution = first_number + second_number;
        } else if (arithmetic_symbol == '-') {
            arithmetic_solution = first_number - second_number;
        } else if (arithmetic_symbol == '*') {
            arithmetic_solution = first_number * second_number;
        } else if (arithmetic_symbol == '/') {
            arithmetic_solution = first_number / second_number;
        } else {
            return;
        } 

        std::cout << first_number << " " << arithmetic_symbol << " " << 
            second_number << " is " << arithmetic_solution << '\n';
    }