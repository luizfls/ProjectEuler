#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <string>

std::multiset<unsigned int> get_digits(unsigned long n)
{
    std::string s = std::to_string(n);
    std::multiset<unsigned int> digits;
    std::transform(s.begin(), s.end(), std::inserter(digits, digits.end()),
                   [](std::string::value_type c) -> unsigned int
                   { return c - '0'; });
    return digits;
}

int main(int argc, char* argv[])
{
    for(unsigned int i = 1u; ; i *= 10u)
    {
        for(unsigned int j = i; j <= j * 5 / 3; ++j)
        {
            auto digits1 = get_digits(j);
            auto digits2 = get_digits(j * 2);
            auto digits3 = get_digits(j * 3);
            auto digits4 = get_digits(j * 4);
            auto digits5 = get_digits(j * 5);
            auto digits6 = get_digits(j * 6);

            if(digits1 == digits2 && digits1 == digits3 && digits1 == digits4 &&
               digits1 == digits5 && digits1 == digits6)
            {
                std::cout << j << std::endl;
                goto exit;
            }
        }
    }

exit:
    return 0;
}
