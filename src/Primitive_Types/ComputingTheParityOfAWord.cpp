#include <iostream>
#include <unordered_map>
#include <cmath>

/**
 * O(n) time complexity
 */
short sol1(unsigned long n)
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

/**
 * O(k) is time complexity, where k is the number of set bits
 */
short sol2(unsigned long n)
{
    short result = 0;
    while (n)
    {
        /*
            r, k = 1
            0, 1 -> r = 1
            1, 1 -> r = 0
        */
        result ^= 1;
        n &= (n - 1); // Drops the lowest set bit of n
    }
    return result;
}

/**
 * O(n/l) time complexity
 * n - number of bits
 * l - number of bits in a group
 */
std::unordered_map<unsigned long, short> preprocess()
{
    std::unordered_map<unsigned long, short> parity_map;
    for(int i = 0; i < 16; i++)
    {
        unsigned long word = pow(2, i);
        parity_map[word] = sol2(word);
    }
    return parity_map;
}

/**
 * Optimal solution for lot of parity computations.
 * O(n/l) is time complexity, n - number of bits in a word, l - number of bits in per group
 */ 
short sol3(unsigned long n, std::unordered_map<unsigned long, short> parity_map)
{
    const int group_size = 16; 
    const int mask = 0xFFFF;
    unsigned long first_group = (n >> (3 * group_size));
    unsigned long second_group = ((n >> (2 * group_size)) & mask); 
    unsigned long third_group = ((n >> group_size) & mask);
    unsigned long fourth_group = (n & mask);
    return (parity_map[first_group] ^ parity_map[second_group] ^ parity_map[third_group] ^ parity_map[fourth_group]);
}

/**
 * Time complexity is O(log(n))
 */
short sol4(unsigned long n)
{
    n ^= (n >> 32);
    n ^= (n >> 16); 
    n ^= (n >> 8); 
    n ^= (n >> 4); 
    n ^= (n >> 2); 
    n ^= (n >> 1); 
    return (n & 0x1); // only last bit
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
    short method;
    std::cout << "Enter a number of approach you want to use:\n";
    std::cin >> method;
    unsigned long n;
    std::cout << "Enter a number for parity calculation:\n";
    std::cin >> n;
    short parity;
    std::unordered_map<unsigned long, short> parity_map = preprocess(); // key - word, val - parity
    switch (method)
    {
    case 1:
        parity = sol1(n);
        break;
    case 2:
        parity = sol2(n);
        break;
    case 3:
        parity = sol3(n, parity_map);
        break;
    default:
        parity = sol4(n);
        break;
    }
    std::cout << "Parity of " << n << " is " << parity << ".\n";
}