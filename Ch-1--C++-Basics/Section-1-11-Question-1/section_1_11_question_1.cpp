#include <iostream>

int main() {
    std::cout << "Enter and integer: ";

    int num{ };
    std::cin >> num;

    std::cout << "Double " << num << " is: " << 2*num << '\n';
    std::cout << "Triple " << num << " is: " << 3*num << '\n';

    return 0;
}