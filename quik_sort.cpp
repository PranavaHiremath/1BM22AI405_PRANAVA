#include <iostream>
#include <cstdlib>
#include <ctime>

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function for Quicksort
int partition(int arr[], int low, int high, int& operations) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        operations++; // Increment operation count

        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Quicksort function
void quicksort(int arr[], int low, int high, int& operations) {
    if (low < high) {
        int pi = partition(arr, low, high, operations);

        quicksort(arr, low, pi - 1, operations);
        quicksort(arr, pi + 1, high, operations);
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    // Generate random numbers
    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Generating random numbers between 0 and 99
    }

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int operations = 0;
    quicksort(arr, 0, n - 1, operations);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Number of basic operations: " << operations << std::endl;

    return 0;
}
