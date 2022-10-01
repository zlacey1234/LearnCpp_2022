#include "io.h"
#include <iostream>

int ReadNumber() {
    std::cout << "Enter a number between 0 and 9 (inclusively): ";

    int number { };
    std::cin >> number;

    if ((number <= 9) && (number >= 0)) {
        return number;
    } else {
        ReadNumber();
    }
}
