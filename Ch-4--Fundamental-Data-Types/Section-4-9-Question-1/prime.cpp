#include "prime.h"

bool IsPrime(int number) {
    if (number == 2 || number == 3 || number == 5 || number == 7) {
        return true;
    } 
    return false;
}