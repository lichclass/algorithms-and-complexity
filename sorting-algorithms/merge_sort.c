/**
 * 
 * Merge Sort Algorithm
 * 
 * Description:
 *  Merge sort is a sorting algorithm that follows the divide-and-conquer approach. 
 *  It works by recursively dividing the input array into smaller subarrays and sorting 
 *  those subarrays then merging them back together to obtain the sorted array. (Geeks for Geeks, 2025)
 * 
 * Time Complexity:
 *  - Worst Case: O(n log n)
 *  - Average Case: O(n log n)
 *  - Best Case: O(n log n)
 * 
 * Space Complexity:
 *  - O(n)
 * 
 * Algorithm:
 *  1. Divide the unsorted array into two sub-arrays, half the size of the original.
 *  2. Continue to divide the sub-arrays as long as the current piece of the array has more than one element.
 *  3. Merge two sub-arrays together by always putting the lowest value first.
 *  4. Keep merging until there are no sub-arrays left.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void merge(int arr[], int low, int mid, int high){
    int temp_n = high - low + 1;
    int tempArr[temp_n];

    // Copy data to temp array but should be sorted
    int left_ndx, right_ndx, i;
    for(i = 0, left_ndx = low, right_ndx = mid + 1; left_ndx <= mid && right_ndx <= high; i++){
        if(arr[left_ndx] < arr[right_ndx]){
            tempArr[i] = arr[left_ndx++];
        } else {
            tempArr[i] = arr[right_ndx++];
        }
    }

    // Copy the remaining elements
    while(left_ndx <= mid){
        tempArr[i++] = arr[left_ndx++];
    }

    while(right_ndx <= high){
        tempArr[i++] = arr[right_ndx++];
    }

    // Copy the temp array to the original array
    for(i = 0; i < temp_n; i++){
        arr[low + i] = tempArr[i];
    }

}


void merge_sort(int arr[], int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}


int main() {
    int arr[] = {9, 4, 7, 2, 10, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, 0, n - 1);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++) // Expected output: 1 2 4 6 7 9 10
    {
        printf("%d ", arr[i]);
    }

    return 0;
}