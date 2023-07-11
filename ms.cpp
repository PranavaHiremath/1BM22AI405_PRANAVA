#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Function to perform the merge step of merge sort
void merge(std::vector<int>& arr, int left, int mid, int right, int& operationCount) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        operationCount++; // Count basic operation
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

// Function to perform the merge sort
void mergeSort(std::vector<int>& arr, int left, int right, int& operationCount) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, operationCount);
        mergeSort(arr, mid + 1, right, operationCount);
        merge(arr, left, mid, right, operationCount);
    }
}

int main() {
    std::srand(std::time(0)); // Seed the random number generator

    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::vector<int> arr(n);

    // Generate random numbers
    for (int i = 0; i < n; ++i) {
        arr[i] = std::rand() % 100; // Generate random numbers between 0 and 99
    }

    std::cout << "Input array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int operationCount = 0;
    mergeSort(arr, 0, n - 1, operationCount);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Total basic operations performed: " << operationCount << std::endl;

    return 0;
}
