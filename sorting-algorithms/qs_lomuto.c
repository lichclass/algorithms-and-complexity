/**
 * 
 * Quick Sort Algorithm via Lomuto Partition
 * 
 * Description:
 *  QuickSort is a sorting algorithm based on the Divide and Conquer 
 *  and partitions the given array around the picked pivot by placing 
 *  the pivot in its correct position in the sorted array. (Geeks for Geeks, 2025)
 * 
 *  The Lomuto partition algorithm divides an array based on a pivot element. 
 *  One pointer marks the boundary for elements smaller than the pivot, while the 
 *  other pointer helps in array traversal. As we traverse the array, smaller elements 
 *  are moved to the left of the boundary and boundary expands. After the traversal, 
 *  all elements to the left of the boundary are smaller, and those on the right are 
 *  larger than pivot. (Geeks for Geeks, 2024)
 * 
 * Time Complexity:
 *  - Worst Case: O(n^2)
 *  - Average Case: O(n log n)
 *  - Best Case: O(n log n)
 * 
 * Space Complexity:
 *  - Worst Case: O(n)
 *  - Average Case: (log n)
 *  - Best Case: (log n)
 * 
 * Algorithm:
 *  1. Choose a pivot
 *  2. Partition the array
 *      - Rearrange the array around the pivot (left - less than the pivot, right - more than the pivot).
 *  3. Recursively Call: Recursively apply the same process to the two partitioned 
 *      sub-arrays (left and right of the pivot).
 *  4. Stop when only one element is left in the array
 * 
 */


#include <stdio.h>
#include <stdlib.h>


/* Utility Function */
void swap(int *, int *);


int lomuto_partition(int arr[], int low, int high) {
    int i, j;
    int pivot = arr[high];

    i = low; // Iterator for swapping in the lower half
    for(j = low; j < high; j++){
        if(pivot >= arr[j]){
            // Swap
            swap(arr + i, arr + j);
            i++;
        }
    }

    // Swapping the pivot and placing it in the middle
    swap(arr + i, arr + high);
    return i;
}


void quick_sort(int arr[], int low, int high){
    if(low < high){
        int p_ndx = lomuto_partition(arr, low, high);
        quick_sort(arr, low, p_ndx - 1);
        quick_sort(arr, p_ndx + 1, high);
    }
}


int main() {
    int arr[] = {9, 4, 7, 2, 10, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, n - 1);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++) // Expected output: 1 2 4 6 7 9 10
    {
        printf("%d ", arr[i]);
    }

    return 0;
}


/* Utility Function */
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}