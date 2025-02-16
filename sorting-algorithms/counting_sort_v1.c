/**
 * 
 * Counting Sort Algorithm Version 1
 * 
 * Description:
 *  This algorithm is a sorting algorithm that is based on the concept of counting.
 *  It works by counting the frequency of each element in the array and then 
 *  placing the elements in the original array. (Geeks for Geeks, 2025)
 * 
 * Time Complexity:
 *  - Worst Case: O(n + k)
 *  - Average Case: O(n + k)
 *  - Best Case: O(n + k)
 * 
 * Space Complexity:
 *  - Worst Case: O(n + k)
 *  - Average Case: O(n + k)
 *  - Best Case: O(n + k)
 * 
 * Algorithm:
 *  1. Find the largest number in the array.
 *  2. Initialize the count array.
 *  3. Count the Frequency of each array element.
 *  4. Calculate the cumulative sum of the count array.
 *  5. Initialize output array.
 *  6. Place the elements in the output array.
 *  7. Place the elements in the original array.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

void counting_sort(int arr[], int n){
    
    // Find the largest number
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }

    // Initialize the count array
    int count[max + 1];
    for(int i = 0; i <= max; i++){
        count[i] = 0;
    } 

    // Count the Frequency of each array element
    for(int i = 0; i < n; i++){
        count[arr[i]]++;
    }

    // Calculate the cumulative sum of the count array
    for(int i = 1; i <= max; i++){
        count[i] += count[i - 1];
    }

    // Initialize output array
    int output[n];

    // Place the elements in the output array
    for(int i = n - 1; i >= 0; i--){
        int idx = --count[arr[i]];
        output[idx] = arr[i];
    }

    // Place the elements in the original array
    for(int i = 0; i < n; i++){
        arr[i] = output[i];
    }

}

int main() {
    int arr[] = {3, 2, 1, 3, 5, 6, 3, 2, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    counting_sort(arr, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++) // Expected output: 1 2 2 3 3 3 4 5 5 6
    {
        printf("%d ", arr[i]);
    }

    return 0;
}