#include <iostream>

unsigned long ClosestIntSameBitCount(unsigned long num)
{
    const int kNumUnsignBits = 64;
    for(int i = 0; i < kNumUnsignBits - 1; i++)
    {
        int k2 = ((num >> i) & 1);
        int k1 = ((num >> (i + 1)) & 1);
        if(k1 != k2)
        {
            const int mask = (1UL << i) | (1UL << (i + 1));
            num ^= mask;
            return num;
        }
    }
}

/**
 * Define the weight of a nonnegative integer x to be the number of bits that are set to 1 in its
 * binary representation. For example, since 92 in base-2 equals (1011100)2, the weight of 92 is 4.
 * 
 * Write a program which takes as input a nonnegative integer x and returns a number y which is not
 * equal to x, but has the same weight as x and their difference, |y - x|, is as small as possible.
 * You can assume x is not 0, or all 1s. For example, is x = 6, you should return 5.
 */
int main()
{
    std::cout << "Enter a nonnegative integer:\n";
    unsigned long num;
    std::cin >> num;
    std::cout << "A closest integer with the same weight as " << num << " is " << ClosestIntSameBitCount(num) << ".\n";
}