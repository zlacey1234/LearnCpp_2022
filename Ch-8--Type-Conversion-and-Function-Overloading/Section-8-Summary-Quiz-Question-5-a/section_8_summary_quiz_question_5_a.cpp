#include <iostream>

template <typename T>
T Add(T x, T y) {
    return x + y;
}

int main() {
    std::cout << Add(2, 3) << '\n';
    std::cout << Add(1.2, 3.4) << '\n';

    return 0;
}
