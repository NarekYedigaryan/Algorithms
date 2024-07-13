#include "./DynamicArray.h"

int main()
{
    DynamicArray arr = {1,2,3,4,5};
    // arr.Insert(2,9);
    
    // std::cout<<arr.Include(3);
    // arr.Reserve(3);
    // arr.Push_Back(8);
    // std::cout<<arr.Size()<<" "<<arr.Capacity();
    arr.Remove(2);
    // for (size_t i = 0; i < arr.Size(); i++)
    // {
    //     std::cout<< arr[i]<<" ";
    // }
    // std::cout<<arr.IsEmpty();
    // std::cout<<arr;
    arr.~DynamicArray();
    // std::cout<<arr[0];
    std::cout<<arr.IsEmpty();
}