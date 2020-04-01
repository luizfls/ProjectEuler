#include <cmath>
#include <iostream>
#include <string>

bool hasForm(long n)
{
    std::string s = std::to_string(n);
    return s[0] == '1' &&
           s[2] == '2' &&
           s[4] == '3' &&
           s[6] == '4' &&
           s[8] == '5' &&
           s[10] == '6' &&
           s[12] == '7' &&
           s[14] == '8' &&
           s[16] == '9' &&
           s[18] == '0';
}

int main(int argc, char* argv[])
{
    long lower_bound = std::sqrt(1020304050607080900.);
    long upper_bound = std::sqrt(1929394959697989990.);

    for(long i = lower_bound; i <= upper_bound; i = i + 10l)
    {
        if(hasForm(i * i))
        {
            std::cout << i << std::endl;
            break;
        }
    }

    return 0;
}
