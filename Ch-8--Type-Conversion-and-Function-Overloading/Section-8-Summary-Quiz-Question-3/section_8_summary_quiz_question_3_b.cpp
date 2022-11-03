#include <iostream>

void print() {
    std::cout << "void\n";
}

void print(int x = 0) {
    std::cout << "int " << x << '\n';
}

void print(double x) {
    std::cout << "double " << x << '\n';
}

int main() {
    print(5.0f);
    print();

    return 0;
}

/** Section 8 Summary Quiz Question 3b
 *
 *  This won't compile since the overload function print can not be ifferdentiated without the
 *  differentiating parameters. It specifically can't differentiate between the 'print()' and
 *  'print(int x = 0)' since default arguments aren't counted for resolving overloaded functions.
 *
 */
