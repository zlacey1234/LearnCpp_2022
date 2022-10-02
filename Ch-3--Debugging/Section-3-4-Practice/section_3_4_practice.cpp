#include <iostream>

int Add(int x, int y) {
    return x + y;
}

void PrintResult(int z) {
    std::cout << "The answer is: " << z << '\n';
}

int GetUserInput() {
    std::cout << "Enter a number: ";
    
    int x{ };
    std::cin >> x;

    return x;
}

int main() {
    int x{ GetUserInput() };
    int y{ GetUserInput() };

    std::cout << x << " + " << y << '\n';

    int z{ Add(x, y) };
    PrintResult(z);

    return 0;
}