#include <iostream>
  
int main()
{
    long long x = (80U << (7*8)) |
        (0U << (6*8)) |
        (0U << (5*8)) |
        (0U << (4*8)) |
        (0U << (3*8)) |
        (0U << (2*8)) |
        (0U << (1*8)) |
        (0U);
    std::cout << "x = " << (80LL << 56) << '\n';
}