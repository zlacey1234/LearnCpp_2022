#include <iostream>

int ReadNumber() {
    std::cout << "Please enter a number: ";

    int x{ };
    std::cin >> x;

    return x;
}

void WriteAnswer(int x) {
    std::cout << "The quotient is: " << x << '\n';
}

int main() {
    int x{ ReadNumber() };
    int y{ ReadNumber() };

    WriteAnswer(x/y);

    return 0;
}