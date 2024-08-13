#include <iostream>

int main()
{
  int a = 9;
    auto it = [&]()
    {
      a=11;
    };
  std::cout<<a;
}