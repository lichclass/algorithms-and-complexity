/**
 * 
 * Radix Sort Algorithm (Least Significant Digit)
 * 
 * Description:
 *  Radix sort is a sorting algorithm that is based on the concept of grouping elements
 *  based on their significant digits. It is a comparison-based sorting algorithm that
 *  uses a stable sorting algorithm. (Geeks for Geeks, 2025)
 * 
 * Time Complexity:
 *  - Worst Case: O(n * d)
 *  - Average Case: O(n * d)
 *  - Best Case: O(n * d)
 * 
 * Space Complexity:
 *  - Worst Case: O(n + k)
 *  - Average Case: O(n + k)
 *  - Best Case: O(n + k)
 * 
 * Algorithm:
 *  1. Find the largest number in the array.
 *  2. Find the number of digits in the largest number.
 *  3. Initialize the buckets.
 *  4. LSD Radix Sort process
 *      - Divide the array into buckets based on the digits.
 *      - Transfer the elements from the buckets to the original array.
 *  5. Repeat the process until all digits are sorted.
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *bucket;
    int lastNdx;
} Bucket;

void radix_sort_lsd(int arr[], int n) {
    
    // Find the largest number
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Initialize the buckets
    Bucket buckets[10];
    for (int i = 0; i < 10; i++) {
        buckets[i].bucket = (int *)malloc(n * sizeof(int));
        buckets[i].lastNdx = -1;
    }

    // LSD Radix Sort process
    int exp = 1;
    for(exp = 1; max / exp > 0; exp *= 10){
        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / exp) % 10;
            buckets[digit].bucket[++buckets[digit].lastNdx] = arr[i];
        }

        // Transfer the elements from the buckets to the original array
        int arrIdx = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j <= buckets[i].lastNdx; j++) {
                arr[arrIdx++] = buckets[i].bucket[j];
            }
            buckets[i].lastNdx = -1; // Reset the bucket index
        }
    }
}

int main() {
    int arr[] = {821, 502, 200, 34, 2, 103, 26, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    radix_sort_lsd(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
