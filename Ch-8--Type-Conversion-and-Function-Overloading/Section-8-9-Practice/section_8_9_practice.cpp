#include <iostream>

int add(int x, int y) {
    return x + y;
}

double add(double x, double y) {
    return x + y;
}


int main() {
    std::cout << add(1, 2);
    std::cout << '\n';

    std::cout << add(1.2, 3.4);
    std::cout << '\n';

    return 0;
}