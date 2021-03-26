#include <iostream>

int sol1(unsigned long n)
{
    short result = 0;
    while (n)
    {
        /*
            r, n
            0, 0 -> r = 0
            0, 1 -> r = 1
            1, 0 -> r = 1
            1, 1 -> r = 0
        */
        result ^= (n & 1); // ^ is xor operator
        n >>= 1;
    }
    return result;
}

int sol2(unsigned long n)
{
    
}

int sol3(unsigned long n)
{
    
}

int sol4(unsigned long n)
{
    
}

/**
 * The parity of a binary word is 1 if the number of 1s in the word is odd; otherwise, 
 * it is 0. For example, the parity of 1011 is 1, and the parity of 10001000 is 0. Parity
 * checks are used to detect single bit errors in data storage and communication. It is 
 * fairly straightforward to write code that computes the parity of a single 64-bit word.
 * How would you compute the parity of a very large number of 64-bit words?
 */
int main()
{
    int method;
    std::cout << "Enter a number of approach you want to use:\n";
    std::cin >> method;
    unsigned long n;
    std::cout << "Enter a number for parity calculation:\n";
    std::cin >> n;
    int parity;
    switch (method)
    {
    case 1:
        parity = sol1(n);
        break;
    case 2:
        parity = sol2(n);
        break;
    case 3:
        parity = sol3(n);
        break;
    default:
        parity = sol4(n);
        break;
    }
    std::cout << "Parity of " << n << " is " << parity << ".\n";
}