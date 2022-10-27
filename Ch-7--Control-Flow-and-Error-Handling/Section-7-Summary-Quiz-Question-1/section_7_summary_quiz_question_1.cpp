#include <iostream>
#include "constants.h"

double CalculateHeight(double initial_height, int seconds) {
    double distance_fallen { my_constants::gravity * seconds * seconds / 2 };
    double height_now { initial_height - distance_fallen };

    // Check whether we've gone under the ground
    // If so, set the height to ground-level
    if (height_now < 0.0) {
        return 0.0;
    } else {
        return height_now;
    }
}

bool CalculateAndPrintHeight(double initial_height, int time) {
    double current_height{ CalculateHeight(initial_height, time) };
    std::cout << "At " << time << " seconds, the ball is at height: " 
        << current_height << '\n';

    return (current_height == 0.0);
}

int main() {
    std::cout << "Enter the initial height of the tower in meters: ";
    double initial_height{};
    std::cin >> initial_height;

    int seconds{ 0 };

    while (!CalculateAndPrintHeight(initial_height, seconds)) {
        seconds++;
    }

    return 0;
}