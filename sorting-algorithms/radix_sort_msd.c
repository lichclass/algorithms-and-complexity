#include <stdio.h>
#include <stdlib.h>

// Define a bucket structure
typedef struct {
    int *bucket;
    int lastNdx;
} Bucket;

// Function to get the digit at a specific position (MSD first)
int get_digit(int num, int digit_place) {
    while (digit_place > 1) {
        num /= 10;
        digit_place--;
    }
    return num % 10;
}

// Recursive MSD Radix Sort function
void msd_radix_sort(int arr[], int n, int digit_place) {
    if (n <= 1 || digit_place == 0) {
        return; // Base case: Single element or no more digits to process
    }

    // Initialize buckets
    Bucket buckets[10];
    for (int i = 0; i < 10; i++) {
        buckets[i].bucket = (int *)malloc(sizeof(int) * n);
        buckets[i].lastNdx = -1;
    }

    // Distribute numbers into buckets based on the current digit
    for (int i = 0; i < n; i++) {
        int digit = get_digit(arr[i], digit_place);
        buckets[digit].bucket[++buckets[digit].lastNdx] = arr[i];
    }

    // Collect sorted numbers back into the array
    int index = 0;
    for (int i = 0; i < 10; i++) {
        if (buckets[i].lastNdx >= 0) {  // If bucket is not empty
            msd_radix_sort(buckets[i].bucket, buckets[i].lastNdx + 1, digit_place - 1);
            for (int j = 0; j <= buckets[i].lastNdx; j++) {
                arr[index++] = buckets[i].bucket[j];
            }
        }
        free(buckets[i].bucket);  // Free memory
    }
}

// Main function to initialize MSD Radix Sort
void radix_sort_msd(int arr[], int n) {
    // Find the largest number
    int largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (largest < arr[i]) {
            largest = arr[i];
        }
    }

    // Find the number of digits in the largest number
    int no_digits = 0;
    while (largest > 0) {
        largest /= 10;
        no_digits++;
    }

    // Call the recursive MSD Radix Sort
    msd_radix_sort(arr, n, no_digits);
}


int main() {
    int arr[] = {821, 502, 200, 34, 2, 103, 26, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    radix_sort_msd(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}