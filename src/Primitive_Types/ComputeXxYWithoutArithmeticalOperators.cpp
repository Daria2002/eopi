#include <iostream>

/**
 * O(n)
 */
unsigned add(unsigned x, unsigned y)
{
    unsigned sum = 0, carryin = 0, k = 1, temp_x = x, temp_y = y;
    while(temp_x || temp_y)
    {
        unsigned x_k = x & k, y_k = y & k;
        unsigned carryout = (x_k & y_k) | (x_k & carryin) | (y_k & carryin);
        sum |= (x_k ^ y_k ^ carryin);
        carryin = carryout << 1, k <<= 1, temp_x >>= 1, temp_y >>= 1;
    }
    return sum | carryin;
}

/**
 * O(n^2)
 */
unsigned multiply(unsigned x, unsigned y)
{
    unsigned sum = 0;
    while (x)
    {
        if(x & 1)
        {
            sum = add(sum, y);
        }
        x >>= 1, y <<= 1;
    }
    return sum;
}

/**
 * Write a program that multiplies two nonnegative integers. The only operators you
 * are allowed to use are: assignment, the bitwise operators >>, <<, |, &, ~, ^ and 
 * equality checks and functions that you write yourself. These constraints imply,
 * for example, that you cannot use increment or decrement, or test if x < y.
 */
int main()
{
    unsigned x, y;
    std::cout << "Enter x:\n";
    std::cin >> x;
    std::cout << "Enter y:\n";
    std::cin >> y;
    std::cout << x << " + " << y << " = " << add(x, y) << '\n';
    std::cout << x << " * " << y << " = " << multiply(x, y) << '\n';
}