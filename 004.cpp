#include <cstddef>
#include <iostream>
#include <string>

bool isPalindrome(unsigned int n)
{
    std::string n_str = std::to_string(n);
    for(std::size_t i = 0u; i < n_str.size() / 2u; ++i)
        if(n_str[i] != n_str[n_str.size() - i - 1u])
            return false;
    return true;
}

int main(int argc, char* argv[])
{
    unsigned int biggest_palindrome = 0u;

    for(unsigned int i = 999u; i >= 100u; --i)
    {
        for(unsigned int j = i; j >= 100u; --j)
        {
            auto prod = i * j;

            // early stop -- a small optimization
            if(j == i && prod < biggest_palindrome)
                goto exit;

            if(isPalindrome(prod))
            {
                biggest_palindrome = std::max(prod, biggest_palindrome);
                break;
            }
        }
    }

exit:
    std::cout << biggest_palindrome << std::endl;
    return 0;
}
