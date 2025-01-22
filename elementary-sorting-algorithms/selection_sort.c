#include <stdio.h>

/**
 * Selection Sort Algorithm (Ascending Order)
 * 
 * 1. Start with the first element of the array.
 * 2. Compare the current element with the adjacent element.
 * 3. If the current element is greater than the adjacent element, swap them.
 * 4. Continue this process for the entire array.
 * 5. Repeat the process for the next element until the array is sorted.
 * 
 * Best Case (Time Complexity): O(n^2)
 * Worst Case (Time Complexity): O(n^2)
 * Space Complexity: O(1)
 * 
 */

void selection_sort(int arr[], int size)
{
    int i, j, min_index; // Iterators and min_index to store the index of the smallest element

    for(i = 0; i < size - 1; i++) // Iterate through the array (except the last element, because it will be sorted) 
    {
        min_index = i; // Assume the current element is the smallest

        for(j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j; // Update the min_index if a smaller element is found
            }
        }

        if(min_index != i) // If the smallest element is not the current element, swap them
        {
            // Swap the elements
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }

        // Print the newly sorted array
        printf("Sorted Array (Ascending): ");
        for(i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    // Sample Array
    int arr[] = {3, 4, 1, 2, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Expected Result, f(arr) = {1, 2, 3, 4, 7, 8}
    selection_sort(arr, size);

    return 0;
}