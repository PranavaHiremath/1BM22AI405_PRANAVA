#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to perform insertion sort
void insertionSort(int arr[], int n, int &basicOperations) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            basicOperations += 2; // Counting comparisons and swaps
        }

        arr[j + 1] = key;
        basicOperations++; // Counting the final swap to place the element in the correct position
    }
}

int main() {
    srand(time(0));

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Generating random numbers between 0 and 99
    }

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int basicOperations = 0;

    clock_t startTime = clock(); // Start the clock

    insertionSort(arr, n, basicOperations);

    clock_t endTime = clock(); // End the clock
    double executionTime = double(endTime - startTime) / CLOCKS_PER_SEC;

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Basic operations executed: " << basicOperations << endl;
    cout << "Execution time: " << executionTime << " seconds" << endl;

    return 0;
}

