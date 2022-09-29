#include <iostream>

/* What happens when you enter: 
 * 
 * a) A letter, such as 'h'.
 *      
 *      'You entered 0' 
 *    
 * b) A number with a fractional component (i.e., 0.2 or 3.2).
 * 
 *      'You entered 0'
 *      'You entered 3'
 * 
 *      Type casts the float type to an integer
 * 
 * c) a small negative integer, such as '-3'.
 * 
 *      'You entered -3'
 * 
 * d) A word, such as 'Hello'.
 * 
 *      'You entered 0'
 * 
 * e) A really big number, such as '4000000000'.
 * 
 *      'You entered 2147483647'
 * 
 * f) A small number followed by some letters, such as '123abc'.
 * 
 *      'You entered 123'
 */

int main() {
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    std::cout << "You entered " << x << '\n';

    return 0;
}