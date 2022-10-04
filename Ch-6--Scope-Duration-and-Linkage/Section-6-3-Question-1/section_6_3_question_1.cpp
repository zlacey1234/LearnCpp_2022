#include <iostream>

int GetInteger() {
    std::cout << "Enter an integer: ";

    int user_input{ };
    std::cin >> user_input;

    return user_input;
}

int GetLargerInteger() {
    std::cout << "Enter a larger integer: ";

    int user_input{ };
    std::cin >> user_input;

    return user_input;
}

void PrintValues(int smaller_number, int larger_number) {
    std::cout << "The smaller value is " << smaller_number << '\n';
    std::cout << "The larger value is " << larger_number << '\n';
}


int main() {
    int smaller{ GetInteger() };
    int larger{ GetLargerInteger() };

    int x;

    if (smaller > larger) {
        // number_temp is initialized
        int number_temp{ }; 

        std::cout << "Swapping the values\n";

        number_temp = smaller;
        smaller = larger;
        larger = number_temp;
    } // number_temp is discarded

    PrintValues(smaller, larger);

    return 0;
}