#include "user_io.h"
#include <iostream>

double GetInitialHeight() {
    std::cout << "Enter the height of the tower in meters: ";

    double ball_height_meters { };
    std::cin >> ball_height_meters;

    return ball_height_meters;
}

double CalculateBallHeight(double initial_height_meters, int x_seconds) {
    // Gravitational Acceleration Constant [units: m/(s^2)].
    constexpr double k_gravity { 9.8 };

    double distance_fallen { (k_gravity * (x_seconds * x_seconds)) / 2.0  };

    double calculated_ball_height_meters { initial_height_meters - 
        distance_fallen};

    return calculated_ball_height_meters;
}

void PrintHeight(double height_meters, int x_seconds) {
    if (height_meters <= 0.0 ) {
        std::cout << "At " << x_seconds << 
            " seconds, the ball is on the ground\n";
    } else {
        std::cout << "At " << x_seconds << 
            " seconds, the ball is at height: " << 
            height_meters << " meters\n";
    }
}

void CalculateAndPrintHeight(double initial_height_meters, int x_seconds) {
    const double height { CalculateBallHeight(initial_height_meters, 
        x_seconds) };
    
    PrintHeight(height, x_seconds);
}