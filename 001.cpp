#include <iostream>

int main(int argc, char* argv[])
{
    unsigned int total = 0;
    for(unsigned int i = 1; i < 1000; i++)
        if(i % 3 == 0 || i % 5 == 0)
            total += i;
    std::cout << total << std::endl;
    return 0;
}
