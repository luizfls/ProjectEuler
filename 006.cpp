#include <algorithm>
#include <iostream>

int main(int argc, char* argv[])
{
    // Compute sum of the squares
    unsigned int sum_squares = 0;
    for(unsigned int i = 1u; i <= 100u; ++i)
        sum_squares += (i * i);

    // Compute square of the sum
    unsigned int square_sum = 0;
    for(unsigned int i = 1u; i <= 100u; ++i)
        square_sum += i;
    square_sum *= square_sum;

    // Resolve minuend and subtrahend
    auto larger = std::max(sum_squares, square_sum);
    auto smaller = std::min(sum_squares, square_sum);

    std::cout << larger - smaller << std::endl;

    return 0;
}
