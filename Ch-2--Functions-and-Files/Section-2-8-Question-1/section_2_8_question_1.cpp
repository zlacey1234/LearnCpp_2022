#include <iostream>


int GetInteger();

int main() {
    int x{ GetInteger() };
    int y{ GetInteger() };

    std::cout << x << " + " << y << " is " << x + y << '\n';
    return 0;
}