#include <iostream>

void Merge(int* arr, int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;

    int leftArr[size1];
    int rightArr[size2];

    for (int i = 0; i < size1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < size2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < size1 && j < size2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < size2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void MergeSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

int main() {
    int arr[7] = {1, 4, -66, 2, 66, 7, 0};
    MergeSort(arr, 0, 6);
    for (size_t i = 0; i < 7; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
