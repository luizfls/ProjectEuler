#include <cstddef>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    std::string s = ".";
    for(unsigned int i = 1u; s.size() < 1000001u; ++i)
        s += std::to_string(i);

    unsigned int result = 1u;
    for(std::size_t i = 1u; i <= 1000000u; i *= 10u)
        result *= (s[i] - '0');

    std::cout << result << std::endl;

    return 0;
}
