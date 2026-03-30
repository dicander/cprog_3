#include <iostream>
#include <iomanip>
#include <charconv>

int main() {
    // Iterate through a specific emoji range (e.g., Miscellaneous Symbols and Pictographs)
    for (int codePoint = 0x1F300; codePoint <= 0x1F5FF; ++codePoint) {
        char32_t emoji = codePoint;
        std::cout << std::hex << std::setw(6) << codePoint << ": ";
        std::cout <<  << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
