#include <iostream>

int ReadNumber();
void WriteAnswer(int answer_value);

int main() {
    int user_input_1 { ReadNumber() };
    int user_input_2 { ReadNumber() };

    WriteAnswer( user_input_1 + user_input_2);

    return 0;
}

int ReadNumber() {
    std::cout << "Enter an integer: ";

    int user_input{ };
    std::cin >> user_input;

    return user_input;
}

void WriteAnswer(int answer_value) {
    std::cout << "The answer is " << answer_value << '\n';
}