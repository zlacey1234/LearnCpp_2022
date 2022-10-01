#include "io.h"
#include "prime.h"
#include <iostream>


int main() {
    int input { ReadNumber() };

    std::cout << "The number: " << input << '\n';
    
    if ( IsPrime(input) ) {
        std::cout << "The digit is prime\n";
    } else {
        std::cout << "The digit is not prime\n";
    }

    return 0;
}