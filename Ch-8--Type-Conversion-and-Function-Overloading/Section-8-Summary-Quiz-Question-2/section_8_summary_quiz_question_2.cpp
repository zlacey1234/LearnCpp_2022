#include <iostream>

namespace constants {

inline constexpr double pi{ 3.14159 };
    
} // namespace constants

using Degrees = double;
using Radians = double;

Radians ConvertToRadians(Degrees degrees) {
    return degrees * constants::pi / 180;
}

int main() {
    std::cout << "Enter a number of degrees: ";
    Degrees degrees{};
    std::cin >> degrees;

    Radians radians{ ConvertToRadians(degrees) };
    std::cout << degrees << " degrees is " << radians << " radians.\n";

    // This statement will compile since both Degrees and Radians are aliases for double. 
    radians = degrees;

    return 0;
}