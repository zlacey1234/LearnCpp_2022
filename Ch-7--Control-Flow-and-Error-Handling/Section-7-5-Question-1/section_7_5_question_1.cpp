#include <iostream>


int Calculate(int number_1, int number_2, char math_operator) {
    switch(math_operator) {
        case '+':
        {
            return number_1 + number_2;
        }
        case '-':
        {
            return number_1 - number_2;
        }
        case '*':
        {
            return number_1 * number_2;
        }
        case '/': 
        {
            return number_1 / number_2;
        }
        case '%':
        {
            return number_1 % number_2;
        }
        default:
        {
            std::cerr << "Error! Unrecognized Math Operator Entered\n";
            return 0;
        }
    }
}

int main() {
    std::cout << "Enter an integer: ";
    
    int user_number_1{};
    std::cin >> user_number_1;

    std::cout << "Enter another integer: ";

    int user_number_2{};
    std::cin >> user_number_2;

    std::cout << "Enter a mathematical operator (+, -, *, /, or %): ";
    
    char user_op{};
    std::cin >> user_op;

    std::cout << user_number_1 << ' ' << user_op << ' ' << user_number_2 
        << " is " << Calculate(user_number_1, user_number_2, user_op) << '\n';

    return 0;
}