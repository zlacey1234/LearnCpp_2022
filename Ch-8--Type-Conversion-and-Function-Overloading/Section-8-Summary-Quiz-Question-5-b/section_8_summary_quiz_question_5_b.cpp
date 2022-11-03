#include <iostream>

template <typename T, typename U>
T Mult(T x, U y) {
    return x * y;
}

int main() {
    std::cout << Mult(2, 3) << '\n';
    std::cout << Mult(1.2, 3) << '\n';

    return 0;
}
