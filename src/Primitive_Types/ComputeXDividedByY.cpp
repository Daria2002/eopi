#include <iostream>

unsigned divide(unsigned x, unsigned y)
{
    // todo
    return 0;
}

/**
 * Compute x/y
 * Given two positive integers, compute their quotient, using only the addition, 
 * subtraction, and shifting operators.
 */
int main()
{
    unsigned x = 6, y = 2;
    /*
    std::cout << "Enter x:\n";
    std::cin >> x;
    std::cout << "Enter y:\n";
    std::cin >> y;
    */
    std::cout << x << " / " << y << " = " << divide(x, y) << '\n';
}