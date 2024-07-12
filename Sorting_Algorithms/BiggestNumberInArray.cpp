#include <iostream>


int BiggestNumberInArray(int*,int);

int main()
{
  const int size = 9;
  int arr[size] = {1,9,7,-55,7,-8,77,7,8};
  std::cout<<BiggestNumberInArray(arr,size);
}

int BiggestNumberInArray(int* arr,int size)
{
      if (size == 1) 
        return arr[0]; 
    return std::max(arr[size-1], BiggestNumberInArray(arr, size-1)); 
}
