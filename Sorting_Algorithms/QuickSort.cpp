#include <iostream>
#include <algorithm> 

int partition(int* arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high + 1; 

    while (i < j) {
        do {
            ++i;
        } while (i <= high && arr[i] < pivot);
        
        do {
            --j;
        } while (arr[j] > pivot);

        if (i < j) {
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[j], arr[low]);
    return j;
}

void Quick(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        Quick(arr, low, pi - 1);
        Quick(arr, pi + 1, high);
    }
}

int main() {
    int arr[7] = {1, 4, -66, 2, 66, 7, 0};
    Quick(arr, 0, 6); 
    for (size_t i = 0; i < 7; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
