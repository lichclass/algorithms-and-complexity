#include <stdio.h>
#include <stdlib.h>

int get_power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

void radix_sort_msd(int arr[], int n){

    // Fill up later

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