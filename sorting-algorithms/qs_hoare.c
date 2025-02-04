/**
 * 
 * Quick Sort Algorithm via Hoare Partition
 * 
 * Description:
 *  QuickSort is a sorting algorithm based on the Divide and Conquer 
 *  and partitions the given array around the picked pivot by placing 
 *  the pivot in its correct position in the sorted array. (Geeks for Geeks, 2025)
 * 
 *  Hoare's partitioning algorithm is an efficient way to partition an array 
 *  around a pivot. It’s based on two pointers that start at opposite ends of the array 
 *  and move toward each other until they find elements that need to be swapped. (Geeks for Geeks, 2024)
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
 *      - Rearrange the array around the pivot 
 *        (left - less than and equal to the pivot, right - more than the pivot).
 *  3. Recursively Call: Recursively apply the same process to the two partitioned 
 *      sub-arrays (left and right of the pivot).
 *  4. Stop when only one element is left in the array
 * 
 */


#include <stdio.h>
#include <stdlib.h>


/* Utility Function */
void swap(int *, int *);


int hoare_partition(int arr[], int start, int end){
    int i = start;
    int j = end;
    int pivot = arr[start];

    while(i < j){
        while(arr[i] < pivot){ i++; } // Increment i while it is less than the pivot
        while(arr[j] > pivot){ j--; } // Decrement j while it is greater than the pivot
        swap(arr + i, arr + j); // Swap the current positions
    }

    return j;
}


void quick_sort(int arr[], int start, int end){
    if(start < end){
        int p_ndx = hoare_partition(arr, start, end);
        quick_sort(arr, start, p_ndx);
        quick_sort(arr, p_ndx + 1, end);
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