#include <iostream>
#include <bits/stdc++.h>

void InsertionSort(int*,int);
int main()
{
   const int n = 7;
   int arr[n] = {1,9,-5,3,55,66,7};
   // std::sort(arr,arr+n);
   // for (size_t i = 0; i < n; i++)
   // {
   //   std::cout<<arr[i]<<" ";
   // }
   
    InsertionSort(arr,n);
   for (size_t i = 0; i < n; i++)
   {
    std::cout<<arr[i]<<" ";
   }
}

void InsertionSort(int* arr,int size)
{
   int j = 0; 
   int result = 0;
   for (size_t i = 1; i < size; ++i)
   {
      result = arr[i];
      j=i-1;
      while(j>=0 and arr[j]>result)
      {
        arr[j+1] = arr[j];
        --j;
      }
      arr[j+1] = result;
   }
}
