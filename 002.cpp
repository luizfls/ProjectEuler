#include <iostream>

int main(int argc, char* argv[])
{
    unsigned int prev = 1u;
    unsigned int curr = 1u;
    unsigned int accu = 0u;

    do
    {
        if(curr % 2u == 0u)
            accu += curr;

        curr += prev;
        prev = curr - prev;
    } while(curr < 4000000u);

    std::cout << accu << std::endl;
    return 0;
}

