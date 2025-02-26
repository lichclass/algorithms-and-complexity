/**
 * 
 * Gnome Sort Algorithm
 * 
 * Description:
 *  This algorithm is a comparison-based sorting algorithm that is similar to insertion sort.
 *  It is a variation of the insertion sort algorithm.
 * 
 * Time Complexity:
 *  - Worst Case: O(n^2)
 *  - Average Case: O(n^2)
 *  - Best Case: O(n)
 * 
 * Space Complexity:
 *  - O(1)
 * 
 * Algorithm:
 *  1. Start with the first element of the array.
 *  2. Compare the current element with the adjacent element.
 *  3. If the current element is greater than the adjacent element, swap them.
 *  4. Continue this process for the entire array.
 *  5. Repeat the process for the next element until the array is sorted.
 * 
 */


#include <stdio.h>

void gnome_sort(int arr[], int n) {
    int pos = 0;
    while (pos < n) {
        if(pos == 0 || arr[pos] >= arr[pos - 1]) {
            pos++;
        } else {
            int temp = arr[pos];
            arr[pos] = arr[pos - 1];
            arr[pos - 1] = temp;
            pos--;
        }
    }
}

int main() {
    int arr[] = {4, 5, 2, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    gnome_sort(arr, n);

    printf("Sorted array: "); // Expected output: 1 2 3 3 4 5
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}