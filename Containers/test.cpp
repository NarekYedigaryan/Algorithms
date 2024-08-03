#include <iostream>


void  foo(int a)
{
    std::cout<<"int";
}

void foo(double a)
{
       std::cout<<"double";
}
int main()
{
  foo(false);
}