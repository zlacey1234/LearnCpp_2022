#include <iostream>

int ReadNumber(int x) {
    std::cout << "Please enter a number: ";
    std::cin >> x;

    return x;
}

void WriteAnswer(int x) {
    std::cout << "The sum is: " << x << '\n';
}

int main() {
    int x{ ReadNumber(x) };

    x = x + ReadNumber(x);

    WriteAnswer(x);

    return 0;
}