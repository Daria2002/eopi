#include <iostream>
#include <unordered_map>
#include <cmath>

/* Function to reverse bits of num */
unsigned int reverseBits(unsigned int num)
{
    unsigned short int reverse_num = num;
    for (int i = 0; i < 4; i++)
    {
        if(((num >> i) & 1) != ((num >> 8 - 1 - i) & 1))
        {
            reverse_num ^= (1 << i);
            reverse_num ^= (1 << (8 - 1 - i));
        }
    }
    return reverse_num;
}

std::unordered_map<unsigned int, unsigned int> preprocess()
{
    std::unordered_map<unsigned int, unsigned int> precomputed_reverse;
    for(int word_tmp = 0; word_tmp < pow(2, 8); word_tmp++)
    {
        precomputed_reverse[word_tmp] = reverseBits(word_tmp);
        std::cout << "word_tmp = " << word_tmp << ", reversed = " << precomputed_reverse[word_tmp] << '\n';
    }
    return precomputed_reverse;
}

long long ReverseBits(long long x, std::unordered_map<unsigned int, unsigned int> precomputed_reverse)
{
    const int mask = 0x00FF;
    return 
        precomputed_reverse[x & mask] << (7*8) |
        precomputed_reverse[(x >> 8) & mask] << (6*8) |
        precomputed_reverse[(x >> (8 * 2)) & mask] << (5*8) |
        precomputed_reverse[(x >> (8 * 3)) & mask] << (4*8) |
        precomputed_reverse[(x >> (8 * 4)) & mask] << (3*8) |
        precomputed_reverse[(x >> (8 * 5)) & mask] << (2*8) |
        precomputed_reverse[(x >> (8 * 6)) & mask] << (1*8) |
        precomputed_reverse[(x >> (8 * 7)) & mask]; 
}

/**
 * Write a program that takes a 64-bit word and returns the word consisting of the bits 
 * of the input word in reverse order. For example, if the input is alternating 1s and 0s,
 * i.e., (1010...10), the output should be alteernating 0s and 1s, i.e., (0101...01).
 */
int main()
{    
    std::cout << "Enter number:\n";
    long long n = 0; // 8 bytes = 64 bites
    //std::cin >> n;
    // unsigned short int = 4 bytes = 16 bits
    std::unordered_map<unsigned int, unsigned int> precomputed_reverse = preprocess(); 
    std::cout << "Reversed bits in number " << n << " result in number " << ReverseBits(n, precomputed_reverse) << ".\n";
}