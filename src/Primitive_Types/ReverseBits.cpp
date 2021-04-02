#include <iostream>
#include <unordered_map>

std::unordered_map<long, long> preprocess()
{
    // todo
}

long ReverseBits(long x, std::unordered_map<long, long> precomputed_reverse)
{
    const int group_size = 16;
    const int mask = 0xFFFF;
    return precomputed_reverse[x & mask] << (3*group_size) |
    precomputed_reverse[(x >> group_size) & mask] << (2*group_size) |
    precomputed_reverse[(x >> (group_size * 2)) & mask] << group_size |
    precomputed_reverse[(x >> (group_size * 3)) & mask]; 
}

/**
 * Write a program that takes a 64-bit word and returns the word consisting of the bits 
 * of the input word in reverse order. For example, if the input is alternating 1s and 0s,
 * i.e., (1010...10), the output should be alteernating 0s and 1s, i.e., (0101...01).
 */
int main()
{
    std::cout << "Enter number:\n";
    long n;
    std::cin >> n;
    std::unordered_map<long, long> precomputed_reverse = preprocess();
    std::cout << "Reversed bits in number " << n << " result in number " << ReverseBits(n, precomputed_reverse) << ".\n";
}