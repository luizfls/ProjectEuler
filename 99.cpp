#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <unordered_map>

using Line2Result = std::unordered_map<unsigned int, double>;

Line2Result loadFile()
{
    Line2Result lines;
    std::ifstream file("base_exp.txt");
    for(unsigned int i = 1; i <= 1000; i++)
    {
        int base, exponent;
        char comma;
        file >> base >> comma >> exponent;
        double result = exponent * std::log10(base);
        lines[i] = result;
    }
    return lines;
}

int main(int argc, char* argv[])
{
    auto lines = loadFile();
    auto cmp = [](const Line2Result::value_type& a, const Line2Result::value_type& b)
               { return a.second < b.second; };
    auto maxIt = std::max_element(lines.begin(), lines.end(), cmp);
    std::cout << maxIt->first << std::endl;
    return 0;
}
