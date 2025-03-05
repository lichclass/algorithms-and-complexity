/**
 * 
 * Strand Sort Algorithm Array Version
 * 
 * Description:
 *  This algorithm is a comparison-based sorting algorithm that uses a sublist to sort the original array.
 *  It is a variation of the merge sort algorithm.
 * 
 * Time Complexity
 *  - Worst Case: O(n^2)
 *  - Average Case: O(n^2)
 *  - Best Case: O(n)
 * 
 * Space Complexity
 *  - O(n)
 * 
 * Algorithm:
 *  1. Create a sublist and initialize it to empty
 *  2. Initialize the output array
 *  3. Find the first element of the original array
 *  4. Loop the original array to find the element that is greater than the last element of the sublist
 *  5. Merge the sublist with the output array using two way merge
 *  6. Repeat Step 3 - 5 until the original array is empty
 *  
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void two_way_merge_sorted(int arr1[], int n1, int arr2[], int *n2){
    
    // Initialize the storage for sorted array
    int merged[n1 + *n2];
    int merged_n = 0;

    // Loop until one of the arrays is empty
    int n1_idx = 0;
    int n2_idx = 0;
    while(n1_idx < n1 && n2_idx < *n2){
        merged[merged_n++] = (arr1[n1_idx] < arr2[n2_idx]) ? arr1[n1_idx++] : arr2[n2_idx++];
    }

    // Add the remaining elements
    while(n1_idx < n1){
        merged[merged_n++] = arr1[n1_idx++];
    }

    while(n2_idx < *n2){
        merged[merged_n++] = arr2[n2_idx++];
    }

    // Copy the sorted array to the output array
    for(int i = 0; i < merged_n; i++){
        arr2[i] = merged[i];
    }

    *n2 = merged_n;
}

void strand_sort(int arr[], int n){

    // Initialize the output array
    int output[n];
    int output_n = 0;

    // Loop until the original array is empty
    while(output_n < n){

        // Initialize the sublist array
        int sublist[n];
        int sublist_n = 0;

        // Find the first element of the original array
        int first_idx;
        for(first_idx = 0; first_idx < n && arr[first_idx] == MIN_INT; first_idx++){}

        // If the first idx is not the end of the original array
        if(first_idx < n){
            // Transfer the first element of the original array to the sublist array
            sublist[sublist_n] = arr[first_idx];
            sublist_n++;

            // Set the first element of the original array to the minimum integer value
            arr[first_idx] = INT_MIN;

            // Start from the next element of the first_idx
            // Then, loop to find element that is greater than the last element of the sublist
            int x;
            for(x = first_idx + 1; x < n; x++){
                if(arr[x] > sublist[sublist_n - 1]){    
                    sublist[sublist_n++] = arr[x];
                    arr[x] = INT_MIN;
                }
            }

            two_way_merge_sorted(sublist, sublist_n, output, &output_n);
        }

    }

    // Copy the output array to the original array
    for(int i = 0; i < output_n; i++){
        arr[i] = output[i];
    }
}

int main() {
    int arr[] = {3, 9, 1, 7, 3, 2, 8, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    strand_sort(arr, n);

    printf("Sorted array: "); // Expected output: 1 2 3 3 4 7 8 9
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");    

    return 0;
}