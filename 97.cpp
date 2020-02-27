#include <iostream>
#include <string>

bool isBouncy(int n)
{
  bool increasing = true, decreasing = true;
  std::string digits = std::to_string(n);
  char lastDigit = digits.front();
  for(auto digit : digits)
  {
    if(digit < lastDigit)
      increasing = false;
    else if(digit > lastDigit)
      decreasing = false;

    if(!increasing && !decreasing)
      return true;

    lastDigit = digit;
  }
  return false;
}

int main(int argc, char* argv[])
{
  int nBouncy = 0;
  for(int i = 1; ; ++i)
  {
    if(isBouncy(i))
      nBouncy++;

    if(nBouncy * 100 / i == 99)
    {
      std::cout << i << std::endl;
      break;
    }
  }

  return 0;
}
