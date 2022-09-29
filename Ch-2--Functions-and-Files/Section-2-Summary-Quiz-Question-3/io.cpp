#include "io.h"
#include <iostream>

int ReadNumber() {
    std::cout << "Enter an integer: ";

    int user_input{ };
    std::cin >> user_input;

    return user_input;
}

void WriteAnswer(int answer_value) {
    std::cout << "The answer is " << answer_value << '\n';
}

