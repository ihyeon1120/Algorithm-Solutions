#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int decimal_value;

    std::cin >> std::hex >> decimal_value;

    std::cout << decimal_value << std::endl;

    return 0;
}