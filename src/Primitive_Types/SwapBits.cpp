#include <iostream>

int swap(int n, int i, int j)
{
    // todo
    return 0;
}

/**
 * A 64-bit integer can be viewed as an array of 64 bits, with the bit at index 0
 * corresponding to the least significant bit (LSB), and the bit at index 63 
 * corresponding to the most significant bit (MSB). Implement code that takes as input
 * a 64-bit integer and swaps the bits at indices i and j.
 */
int main()
{
    int n, i, j;
    std::cout << "Enter number to swap:\n";
    std::cin >> n;
    std::cout << "Enter i (first index):\n";
    std::cin >> i;
    std::cout << "Enter j (first index):\n";
    std::cin >> j;
    std::cout << "Result of swapping " << i << " and " << j << " indices of number "
    << n << " is " << swap(n, i, j) << ".\n";
}