#include <iostream>

int main() {
    char start_char{'a'};
    char end_char{'z'};

    int ascii_start{static_cast<int>(start_char)};
    int ascii_end{static_cast<int>(end_char)};

    int ascii_count = ascii_start;

    while (ascii_count <= ascii_end) {
        std::cout << static_cast<char>(ascii_count) << " ASCII code: " 
        << ascii_count << '\n';
        
        ascii_count++;
    }

    return 0;
}