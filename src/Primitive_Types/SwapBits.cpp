#include <iostream>

// O(1) time complexity
long swap(long n, int i, int j)
{
    // check if i-th and j-th bits differ
    int ith_bit = (n >> i) & 1;
    int jth_bit = (n >> j) & 1;
    if(ith_bit != jth_bit)
    {
        // swap bits by flipping their values
        unsigned long mask = (1L << i) | (1L << j);
        n ^= mask;
    }
    return n;
}

/**
 * A 64-bit integer can be viewed as an array of 64 bits, with the bit at index 0
 * corresponding to the least significant bit (LSB), and the bit at index 63 
 * corresponding to the most significant bit (MSB). Implement code that takes as input
 * a 64-bit integer and swaps the bits at indices i and j.
 */
int main()
{
    long n;
    int i, j;
    std::cout << "Enter number to swap:\n";
    std::cin >> n;
    std::cout << "Enter i (first index):\n";
    std::cin >> i;
    std::cout << "Enter j (first index):\n";
    std::cin >> j;
    std::cout << "Result of swapping " << i << " and " << j << " indices of number "
    << n << " is " << swap(n, i, j) << ".\n";
}