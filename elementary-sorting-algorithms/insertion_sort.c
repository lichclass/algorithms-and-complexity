#include <stdio.h>

/**
 * Insertion Sort Algorithm (Ascending Order)
 * 
 * (Swapping)
 * 1. Start with the first element of the array.
 * 2. Compare the current element with the previous element.
 * 3. If the current element is less than the previous element, swap them.
 * 4. Continue this process for the entire array.
 * 5. Repeat the process for the next element until the array is sorted.
 * 
 * (Shifting)
 * 1. Start with the first element of the array.
 * 2. Compare the current element with the previous element.
 * 3. If the current element is less than the previous element, shift the element to the right.
 * 4. Continue this process for the entire array.
 * 5. Repeat the process for the next element until the array is sorted.
 * 
 */

void insertion_sort(int arr[], int size)
{
    int i, j; // Iterators

    for(i = 1; i < size; i++)
    {

        for(j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--)
        {
            // Swap the elements
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }

    // Print the newly sorted array
    printf("Sorted Array (Ascending, Swapping): ");
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion_sort_optimized(int arr[], int size)
{
    int i, j, key; // Iterators and key to store the current element

    for(i = 1; i < size; i++)
    {
        key = arr[i]; // Store the current element in the key variable

        for(j = i - 1; j >= 0 && arr[j] > key; j--)
        {
            arr[j + 1] = arr[j]; // Shift the element to the right
        }

        arr[j + 1] = key; // Insert the key into the correct position
    }


    // Print the newly sorted array
    printf("Sorted Array (Ascending, Shifting): ");
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    // Sample Array
    int arr[] = {3, 4, 1, 2, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Expected Result, f(arr) = {1, 2, 3, 4, 7, 8}
    insertion_sort(arr, size);
    insertion_sort_optimized(arr, size);
    return 0;
}