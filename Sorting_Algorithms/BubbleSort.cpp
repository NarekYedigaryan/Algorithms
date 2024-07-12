#include <iostream>

void BubbleSort(int*,int);
int main()
{
  int arr[7] = {1,9,6,-5,99,6,5};
  BubbleSort(arr,7);
  for (size_t i = 0; i < 7; i++)
  {
    std::cout<<arr[i]<<" ";
  }
  
}

void BubbleSort(int* arr,int size)
{
  bool flag = false;
  for (size_t i = 0; i < size-1; ++i)
  {
    for (size_t j = 0; j < size-1-i; ++j)
    {
       if(arr[j]>arr[j+1])
       {
        std::swap(arr[j],arr[j+1]);
        flag = true;
       }
    }
    if(!flag)
    {
        break;
    }
    
  }
  
}
