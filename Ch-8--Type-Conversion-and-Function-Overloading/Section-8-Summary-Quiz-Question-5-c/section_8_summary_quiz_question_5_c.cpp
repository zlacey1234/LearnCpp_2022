#include <iostream>

template <typename T, typename U>
auto Sub(T x, U y) {
    return x - y;
}

int main() {
    std::cout << Sub(3, 2) << '\n';
    std::cout << Sub(3.5, 2) << '\n';
    std::cout << Sub(4, 1.5) << '\n';

    return 0;
}
