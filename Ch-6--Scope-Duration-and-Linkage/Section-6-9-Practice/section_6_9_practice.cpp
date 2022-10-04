#include "constants.h"

#include <iostream>

int main() {
    std::cout << "Enter a radius: ";
    int radius{ };
    std::cin >> radius;

    int X = 100;
    
    int y = 100 * X;
    int z;

    int x;
    


    std::cout << "The circumference is: " << 
        2.0 * radius * constants::pi << '\n';

    return 0;
}