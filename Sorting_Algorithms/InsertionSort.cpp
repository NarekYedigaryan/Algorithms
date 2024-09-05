#include <iostream>
#include <bits/stdc++.h>

void InsertionSort(std::vector<int>& arr);
int main()
{
   const int n = 7;
   std::vector<int> arr = {1,9,-5,3,55,66,7};
   // std::sort(arr,arr+n);
   // for (size_t i = 0; i < n; i++)
   // {
   //   std::cout<<arr[i]<<" ";
   // }
   
    InsertionSort(arr);
   for (size_t i = 0; i < n; i++)
   {
    std::cout<<arr[i]<<" ";
   }
}

void InsertionSort(std::vector<int>& arr)
{
   int j = 0; 
   for (size_t i = 1; i < arr.size(); ++i)
   {
      j=i;
      while(j>0 and arr[j-1]>arr[j])
      {
        std::swap(arr[j-1] , arr[j]);
        j -= 1;
      }
   }
 
}
