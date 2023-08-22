#include <iostream>

int main() {
    int x { 1 };
    int& ref{ x };

    std::cout << x << ref << std::endl; // prints: 11

    int y{ 2 };
    ref = y;
    y = 3;

    std::cout << x << ref << std::endl; // prints: 22

    x = 4;

    std::cout << x << ref << std::endl; // prints: 44

    return 0;
}