#include <iostream>
#include <list>

/**
 * 0=sunday, 1=monday, 2=tuesday, 3=wednesday, 4=thursday, 5=friday, 6=saturday
 */
struct Day
{
    Day(unsigned int day) : _day(day)
    {}

    void advance(unsigned int days)
    {
        _day += days;
        _day %= 7u;
    }

    bool is_sunday() const
    { return _day == 0u; }

private:
    unsigned int _day;
};

int main(int argc, char* argv[])
{
    auto leap_year   = {31u, 29u, 31u, 30u, 31u, 30u, 31u, 31u, 30u, 31u, 30u, 31u};
    auto common_year = {31u, 28u, 31u, 30u, 31u, 30u, 31u, 31u, 30u, 31u, 30u, 31u};

    // 1 Jan 1900 was a monday
    Day first_day_of_the_month(1u);
    // 1900 was a common year
    for(auto days_in_month : common_year)
        first_day_of_the_month.advance(days_in_month);

    std::list<unsigned int> months_1901_to_2000;
    for(unsigned int year = 1901u; year <= 2000u; ++year)
        months_1901_to_2000.insert(months_1901_to_2000.end(), year % 4 == 0 ? leap_year : common_year);
    months_1901_to_2000.pop_back();

    unsigned int total = first_day_of_the_month.is_sunday() ? 1u : 0u;
    for(auto days_in_month : months_1901_to_2000)
    {
        first_day_of_the_month.advance(days_in_month);
        if(first_day_of_the_month.is_sunday())
            total++;
    }

    std::cout << total << std::endl;
    return 0;
}

