#include <iostream>
#include <unordered_map>
#include <cmath>

/* Function to reverse bits of num */
unsigned int reverseBits(unsigned short int num)
{
    unsigned short int num_of_bits = sizeof(num) * 8;
    unsigned short int reverse_num = 0, i, temp;
    for (i = 0; i < num_of_bits; i++)
    {
        temp = (num & (1 << i));
        if(temp)
            reverse_num |= (1 << ((num_of_bits - 1) - i));
    }
   
    return reverse_num;
}

std::unordered_map<unsigned short int, unsigned short int> preprocess(const int group_size)
{
    std::unordered_map<unsigned short int, unsigned short int> precomputed_reverse;
    const short int mask = 0xFFFF;
    for(unsigned short int word_tmp = 0; word_tmp < pow(2, group_size + 1); word_tmp++)
    {
        precomputed_reverse[word_tmp] = reverseBits(word_tmp);
    }
    return precomputed_reverse;
}

long long ReverseBits(long long x, std::unordered_map<unsigned short int, unsigned short int> precomputed_reverse, const int group_size)
{
    const short int mask = 0xFFFF;
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
    long long n = 1; // 8 bytes = 64 bites
    //std::cin >> n;
    const int group_size = 16; // 2 bytes = 16 bits
    // unsigned short int = 4 bytes = 16 bits
    std::unordered_map<unsigned short int, unsigned short int> precomputed_reverse = preprocess(group_size); 
    std::cout << "Reversed bits in number " << n << " result in number " << ReverseBits(n, precomputed_reverse, group_size) << ".\n";
}