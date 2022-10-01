#include "user_io.h"
#include <iostream>

int main() {
    double first_input { ReadNumber() };
    double second_input { ReadNumber() };

    char arithmetic_operator { GetArithmeticSymbol() };

    PrintArithmeticExpression(first_input, second_input, arithmetic_operator);

    return 0;
}