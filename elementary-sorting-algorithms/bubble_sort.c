#include <stdio.h>

/**
 * Bubble Sort Algorithm (Ascending Order)
 * 
 * 1. Start from the first index (index 0). Compare the current element with the adjacent (next) element.
 *    -> If the current element is greater than the adjacent element, swap them.
 * 2. Move to the next index and repeat Step 1.
 * 3. Continue this process until the end of the array for the current pass. 
 *    At this point, the largest element will have "bubbled up" to the last position in the array.
 * 4. Repeat the above steps for the remaining unsorted portion of the array:
 *    -> On each subsequent pass, reduce the range of the range of comparison by 1
 *    -> i.e stop before the last sorted element
 * 5. Stop when no swaps are required, meaning the array is fully sorted.
 * 
 */

void bubble_sort(int arr[], int size) 
{
    /**
     * The Bubble Sort Algorithm (Ascending Order)
     * Default Bubble Sort
     * 
     * Args:
     *  arr[]: The array to be sorted
     *  size: The size of the array
     * 
     * Returns: void
     */
    
    int i, j; // Variables for the loop; i is the outer loop, j is the inner loop; Iterators

    for (i = 0; i < size - 1; i++) // Outer Loop. Note: size - 1 because we are comparing the last element with the next element
    {
        for (j = 0; j < size - i - 1; j++) // Inner Loop. Note: size - i - 1 because the right subset is decreasing by 1 each time since the other elements are sorted
        {
            if (arr[j] > arr[j + 1]) // If the current element is greater than the next element, swap them
            {
                int temp = arr[j]; // Temporary variable to store the current element
                arr[j] = arr[j + 1]; // Assign the next element to the current element
                arr[j + 1] = temp;
            }
        }
    }

    // Print the newly sorted array
    printf("Sorted Array (Ascending, Default): ");
    for (i = 0; i < size; i++)
    {
         printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort_optimized(int arr[], int size)
{
    /**
     * The Bubble Sort Algorithm (Ascending Order)
     * Optimized Bubble Sort
     * 
     * Optimized Bubble Sort is a variation of the Bubble Sort Algorithm 
     * that stops the sorting process if the array is already sorted.
     * 
     * Args:
     *  arr[]: The array to be sorted
     *  size: The size of the array
     * 
     * Returns: void
     */

    int i, j, swapped = 1; // Variables for the loop; i is the outer loop, j is the inner loop; Iterators

    for (i = 0; i < size - 1 && swapped; i++) // Outer Loop. Note: size - 1 because we are comparing the last element with the next element
    {
        swapped = 0; // Reset the swapped flag to 0
        for (j = 0; j < size - i - 1; j++) // Inner Loop. Note: size - i - 1 because the right subset is decreasing by 1 each time since the other elements are sorted
        {
            if (arr[j] > arr[j + 1]) // If the current element is greater than the next element, swap them
            {
                int temp = arr[j]; // Temporary variable to store the current element
                arr[j] = arr[j + 1]; // Assign the next element to the current element
                arr[j + 1] = temp;

                swapped = 1; // Set the swapped flag to 1
            }
        }
    }

    // Print the newly sorted array
    printf("Sorted Array (Ascending, Optimized): ");
    for (i = 0; i < size; i++)
    {
         printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    
    // Sample Array
    int arr[] = {3, 4, 1, 2, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Expected Result, f(arr) = {1, 2, 3, 4, 7, 8}
    bubble_sort(arr, size);
    bubble_sort_optimized(arr, size);

    return 0;
}