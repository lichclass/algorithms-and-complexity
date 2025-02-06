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
    int left_n = mid - low + 1;
    int right_n = high - mid;

    int *left = (int*)malloc(left_n * sizeof(int));
    int *right = (int*)malloc(right_n * sizeof(int));

    memcpy(left, arr + low, left_n * sizeof(int));
    memcpy(right, arr + mid + 1, right_n * sizeof(int));

    int i;
    int left_ndx = 0;
    int right_ndx = 0;
    for(i = low; left_ndx < left_n && right_ndx < right_n; i++){
        if(right[right_ndx] <= left[left_ndx]){
            arr[i] = right[right_ndx++];
        } else {
            arr[i] = left[left_ndx++];
        }
    }

    if(left_ndx < left_n){
        memcpy(arr + i, left + left_ndx, sizeof(int) * (left_n - left_ndx));
    } 
    
    if(right_ndx < right_n) {
        memcpy(arr + i, right + right_ndx, sizeof(int) * (right_n - right_ndx));
    }

    free(left);
    free(right);
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