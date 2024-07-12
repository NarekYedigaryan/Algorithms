#include <iostream>

void SelectionSort(int*,int);
int main()
{
   int arr[7] = {5,67,9,-4,5,6,8};
   SelectionSort(arr,7);
   for (size_t i = 0; i < 7; i++)
   {
     std::cout<<arr[i]<<" ";
   }
   
}


void SelectionSort(int*arr,int size)
{
   int min_ind = 0;
   for (size_t i = 0; i < size-1; i++)
   {
      min_ind = i;
      for (size_t j = i+1; j < size; j++)
      {
         if(arr[j] < arr[min_ind])
         {
            min_ind = j;
         }
      }
      std::swap(arr[min_ind],arr[i]);
      
   }
   
}
