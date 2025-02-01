#include <stdio.h>
#include <stdlib.h>

/**
 * 
 * Shell Sort Algorithm
 * 
 * Description:
 *  This algorithm is a comparison-based sorting algorithm that uses a gap to sort the original list.
 *  It is a variation of the insertion sort algorithm.
 * 
 * Time Complexity:
 *  - Worst Case: O(n^2)
 *  - Average Case: O(n log n)
 *  - Best Case: O(n log n)
 * 
 * Space Complexity:
 *  - O(1)
 * 
 * Algorithm:
 * 1. Start with a gap of n / 2
 * 2. Insertion sort the elements with the gap
 * 3. Reduce the gap by half
 * 4. Repeat the process until the gap is 0
 * 
 */

void shell_sort(int arr[], int n)
{
    int gap; // gap between elements
    for(gap = n / 2; gap > 0; gap /= 2) { // reduce gap by half
        int i;
        for(i = gap; i < n; i++){ // insertion sort the elements with the gap
            int temp = arr[i];
            int j;
            for(j = i; j >= gap && arr[j - gap] > temp; j -= gap){ // shift elements to the right
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main()
{
    int arr[] = {73, 67, 56, 32, 52, 41, 83, 37, 32, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    shell_sort(arr, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++) // Expected output: 10 32 32 37 41 52 56 67 73 83
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}