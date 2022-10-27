#include <iostream>

int main() {
    int rowIdx{ 1 };

    while (rowIdx <= 5) {
        int colIdx{ 5 };

        while (colIdx > 0) {
            // Prints the Blank Spaces
            if (colIdx > rowIdx) {
                std::cout << "  ";
            } else {
                std::cout << " " << colIdx;
            }
            --colIdx;
        }
        std::cout << '\n';
        ++rowIdx;
    }

    return 0;
}