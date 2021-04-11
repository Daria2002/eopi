#include <iostream>

unsigned divide(unsigned x, unsigned y)
{
    unsigned result = 0;
    int power = 32;
    unsigned long long y_power = static_cast<unsigned long long>(y) << power;
    while (x >= y)
    {
        // todo
    }
    return result;
}

/**
 * Compute x/y
 * Given two positive integers, compute their quotient, using only the addition, 
 * subtraction, and shifting operators.
 */
int main()
{
    unsigned x, y;
    std::cout << "Enter x:\n";
    std::cin >> x;
    std::cout << "Enter y:\n";
    std::cin >> y;
    std::cout << x << " / " << y << " = " << divide(x, y) << '\n';
}