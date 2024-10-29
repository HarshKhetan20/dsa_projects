#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep function

#define ARRAY_SIZE 10 // Define the size of the array

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort function with visualization
void bubbleSort(int arr[], int size) {
    int swapped;

    printf("Initial Array:\n");
    printArray(arr, size);
    sleep(1); // Pause for visualization

    for (int i = 0; i < size - 1; i++) {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;

                // Print the array after each swap
                printArray(arr, size);
                sleep(1); // Delay for visualization
            }
        }
        if (!swapped) break; // If no swaps occurred, the array is sorted
    }

    printf("Sorted Array:\n");
    printArray(arr, size);
}

int main() {
    int arr[ARRAY_SIZE];

    // Generate a random array of integers
    srand(time(0));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }

    // Call bubble sort and visualize
    bubbleSort(arr, ARRAY_SIZE);

    return 0;
}
