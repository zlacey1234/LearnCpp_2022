#include <iostream>

// note: It should be mentioned that the following function is poorly designed 
// for two reasons:
// 
// 1) There's no way to reset s_counter_passes, so the function can't be reused 
//    in a program
//
// 2) The function inscrutably returns a different value after a certain number 
//    of calls
bool passOrFail() {
    static int s_counter_passes { 0 };
    ++s_counter_passes;
    return s_counter_passes <= 3;
}

int main() {
    std::cout << "User #1: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #2: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #3: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #4: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #5: " << (passOrFail() ? "Pass\n" : "Fail\n");
}