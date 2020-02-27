#include <iostream>

int main(int argc, char* argv[])
{
    // 2^7830457
    unsigned long int power = 1;
    for(int i = 0; i < 7830457; ++i)
        power = (power * 2) % 10000000000;

    // 28433 * 2^7830457
    unsigned long int product = 0;
    for(int i = 0; i < 28433; ++i)
        product = (product + power) % 10000000000;

    // 28433 * 2^7830457 + 1
    unsigned long int result = product + 1;
    std::cout << result << std::endl;
    return 0;
}