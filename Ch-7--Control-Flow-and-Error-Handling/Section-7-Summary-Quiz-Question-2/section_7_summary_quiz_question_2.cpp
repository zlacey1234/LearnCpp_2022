#include <iostream>
#include <cassert>
#include <cmath>

bool IsPrime(int x) {
    if (x <= 1) {
        return false;
    } 

    int max_test{ static_cast<int>(std::sqrt(x)) };

    for (int test{ 2 }; test <= max_test; ++test) {
        if (x % test == 0 ) {
            return false;
        }
    }

    return true;
}

int main() {
    assert(!IsPrime(0));
    assert(!IsPrime(1));
    assert(IsPrime(2));
    assert(IsPrime(3));
    assert(!IsPrime(4));
    assert(IsPrime(5));
    assert(IsPrime(7));
    assert(!IsPrime(9));
    assert(IsPrime(11));
    assert(IsPrime(13));
    assert(!IsPrime(15));
    assert(!IsPrime(16));
    assert(IsPrime(17));
    assert(IsPrime(19));
    assert(IsPrime(97));
    assert(!IsPrime(99));
    assert(IsPrime(13417));

    std::cout << "Success!\n";

    return 0;
}