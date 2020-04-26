#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

unsigned int add_square_digits(unsigned int n)
{
    std::string s = std::to_string(n);
    std::vector<unsigned int> v(s.size());
    std::transform(s.begin(), s.end(), v.begin(),
                   [](std::string::value_type c) -> unsigned int
                   { return c - '0'; });
    std::transform(v.begin(), v.end(), v.begin(),
                   [](unsigned int x) -> unsigned int
                   { return x * x; });
    return std::accumulate(v.begin(), v.end(), 0u);
}

int main(int argc, char* argv[])
{
    unsigned int total = 0u;
    for(unsigned int i = 1u; i < 10000000u; ++i)
    {
        unsigned int j = i;
        do
        {
            j = add_square_digits(j);
            if(j == 89u)
                total++;
        } while(j != 1u && j != 89u);
    }

    std::cout << total << std::endl;
    return 0;
}
