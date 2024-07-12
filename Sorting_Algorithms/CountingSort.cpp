#include <iostream>

void CountingSort(int*, int);
int main()
{
    int arr[12] = {1, 12, 5, 12, 5, 1, 1, 1, 12, 5, 5, 5};
    CountingSort(arr, 12);
}

void CountingSort(int* arr, int size)
{
    int n = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > n)
        {
            n = arr[i];
        }
    }

    int arr1[n + 1] = {0}; 
    for (int i = 0; i < size; i++)
    {
        arr1[arr[i]]++;
    }

    int new_arr[size] = {0};
    int ind = 0;
    for (int i = 1; i < n + 1; i++) 
    {
        arr1[i] += arr1[i - 1];
    }

    for (int i = size - 1; i >= 0; --i) 
    {
        new_arr[arr1[arr[i]] - 1] = arr[i];
        --arr1[arr[i]];
    }

    for (int i = 0; i < size; i++) 
    {
        std::cout << new_arr[i] << " ";
    }
}
