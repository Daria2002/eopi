#include <iostream>

long ReverseBits(long x)
{
    // todo
    return 0;
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
    std::cout << "Reversed bits in number " << n << " result in number " << ReverseBits(n) << ".\n";
}