#include "user_io.h"

int main() {
    double initial_height{ GetInitialHeight() };

    CalculateAndPrintHeight(initial_height, 0);
    CalculateAndPrintHeight(initial_height, 1);
    CalculateAndPrintHeight(initial_height, 2);
    CalculateAndPrintHeight(initial_height, 3);
    CalculateAndPrintHeight(initial_height, 4);
    CalculateAndPrintHeight(initial_height, 5);

    return 0;
}