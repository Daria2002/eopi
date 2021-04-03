#include <iostream>
#include <unordered_map>
#include <cmath>

std::unordered_map<unsigned long, unsigned long> preprocess(const int group_size)
{
    std::unordered_map<unsigned long, unsigned long> precomputed_reverse;
    const int mask = 0xFFFF;
    for(int i = 1; i < group_size; i++)
    {
        unsigned long word_left = pow(2, i - 1);
        unsigned long word_right = pow(2, i);
        for(unsigned long word_tmp = word_left; word_tmp < word_right; word_tmp++)
        {
            // todo: check this 
            precomputed_reverse[word_tmp] = word_tmp ^ mask;
        }
    }
    return precomputed_reverse;
}

long ReverseBits(long x, std::unordered_map<unsigned long, unsigned long> precomputed_reverse, const int group_size)
{
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
    const int group_size = 16;
    std::unordered_map<unsigned long, unsigned long> precomputed_reverse = preprocess(group_size);
    std::cout << "Reversed bits in number " << n << " result in number " << ReverseBits(n, precomputed_reverse, group_size) << ".\n";
}