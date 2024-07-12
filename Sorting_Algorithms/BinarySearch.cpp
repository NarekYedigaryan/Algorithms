#include <iostream>

int BinarySearch_iterative(int*,int,int);
int BinarySearch_recursive(int*,int,int,int);
int main()
{
   int arr[7] = {1,2,3,4,5,6,7}; 

//  std::cout<<BinarySearch_iterative(arr,7,9);
   std::cout<<BinarySearch_recursive(arr,6,0,6);

}

int BinarySearch_iterative(int* arr,int size,int target)
{
  int start = 0;
  int end = size - 1;
  int mid = 0;
  while(start <= end)
  {
    mid = start + (end-start)/2;
    if(target == arr[mid])
    {
        return mid;
    }
    else if(arr[mid] <= target)
    {
        start = mid + 1;
    }
    else
    {
        end = mid - 1;
    }
  }
  return -1;
}

int BinarySearch_recursive(int* arr,int target,int start,int end)
{
    int mid = start + (end-start)/2;
    if(start>=end)
    {
        return -1;
    }
    if(target == arr[mid])
    {
        return mid;
    }
    else if(arr[mid] <= target)
    {
       return BinarySearch_recursive(arr,target,mid+1,end);
    }
    else
    {
       return BinarySearch_recursive(arr,target,start,mid-1);
    }
}