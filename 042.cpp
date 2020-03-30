#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <string>
#include <unordered_set>

std::string read_file(std::string filepath)
{
    std::ifstream t(filepath);
    std::stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

template <typename OutputIterator>
void split(const std::string& s, OutputIterator result)
{
    std::istringstream iss(s);
    std::string word;
    while(std::getline(iss, word, ',')) // split per comma
    {
        word = word.substr(1, word.size() - 2); // remove leading and trailing quotes
        result = word;
    }
}

unsigned int get_longest_word_size(const std::unordered_set<std::string>& words)
{
    auto size_cmp = [](const std::string& s1, const std::string& s2)
                    { return s1.size() < s2.size(); };
    auto longest_word_it = std::max_element(words.begin(), words.end(), size_cmp);
    return longest_word_it->size();
}

std::unordered_set<unsigned int> compute_triangle_numbers(unsigned int upper_bound)
{
    std::unordered_set<unsigned int> triangle_numbers;
    for(unsigned int n = 1u; ; ++n)
    {
        unsigned int tn = n * (n + 1u) / 2u;
        if(tn <= upper_bound)
            triangle_numbers.insert(tn);
        else
            break;
    }
    return triangle_numbers;
}

bool is_triangle_word(const std::string& word, const std::unordered_set<unsigned int>& triangle_numbers)
{
    auto letter_value = [](unsigned int curr, char c)
                        { return curr + (c - 'A' + 1); };
    auto word_value = std::accumulate(word.begin(), word.end(), 0u, letter_value);
    return triangle_numbers.count(word_value) > 0u;
}

int main(int argc, char* argv[])
{
    auto s = read_file("p042_words.txt");

    std::unordered_set<std::string> words;
    split(s, std::inserter(words, words.end()));

    // compute highest possible word value to be used
    // as an upper bound in triangle number generation
    auto longest_word_size = get_longest_word_size(words);
    auto highest_word_value = longest_word_size * 26u; // assuming all chars are 'Z'
    auto triangle_numbers = compute_triangle_numbers(highest_word_value);

    unsigned int n_triangle_words = 0u;
    for(const auto& word : words)
        if(is_triangle_word(word, triangle_numbers))
            n_triangle_words++;

    std::cout << n_triangle_words << std::endl;

    return 0;
}
