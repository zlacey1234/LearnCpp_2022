#include <iostream>

int main() {
    int outer_idx{ 5 }; 
    
    while (outer_idx >= 1) {
        int inner_idx{ outer_idx };

        while (inner_idx >= 1) {
            std::cout << inner_idx << " ";
            --inner_idx;
        }
        std::cout << '\n';
        --outer_idx;
    }

    return 0;
}