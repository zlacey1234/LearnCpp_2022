#include <iostream>

template <typename T>
int count(T) {
    static int c{ 0 };
    return ++c;
}

int main() {
    std::cout << count(1) << '\n';
    std::cout << count(1) << '\n';
    std::cout << count(2.3) << '\n';
    std::cout << count<double>(1) << '\n';

    return 0;
}

/** Section 8 Summary Quiz Question 4
 *
 *  What is the output of this program and why?
 *
 *  The output should be:
 *
 *  1
 *  2
 *  1
 *  2
 *
 *  The first two iterations call count<int>(int)
 *
 *  The third and fourth iterations call count<double>(double)
 *
 */