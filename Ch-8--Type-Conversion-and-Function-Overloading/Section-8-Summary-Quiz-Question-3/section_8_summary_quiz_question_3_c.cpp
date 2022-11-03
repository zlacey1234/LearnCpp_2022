#include <iostream>

void print(long x) {
    std::cout << "long " << x << '\n';
}

void print(double x) {
    std::cout << "double " << x << '\n';
}

int main() {
    print(5);

    return 0;
}

/** Section 8 Summary Quiz Question 3c
 *
 *  This won't compile since the compiler can not differentiate between the overloaded functions.
 *  Specifically, 'print(long x)' and 'print(double x)' have same conversion method (numeric
 *  conversion) and the compiler can't determine which would be better. 
 *
 */
