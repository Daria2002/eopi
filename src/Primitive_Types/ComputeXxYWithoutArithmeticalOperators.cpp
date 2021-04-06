#include <iostream>

unsigned add(unsigned x, unsigned y)
{

}

unsigned multiply(unsigned x, unsigned y)
{
    
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