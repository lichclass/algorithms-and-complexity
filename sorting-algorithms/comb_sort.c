#include <stdio.h>
#include <stdlib.h>

/**
 * 
 * Comb Sort Algorithm
 * 
 * Description:
 *  Comb Sort is a sorting algorithm that is similar to Bubble Sort, but it uses a gap
 *  between the elements to be compared. The gap is initially set to the length of the array,
 *  and it is reduced by a shrink factor (usually 1.3) in each iteration.
 * 
 *  The algorithm compares elements that are gap distance apart and swaps them if they are in the wrong order.
 *  This process is repeated until the gap becomes 1, at which point the algorithm behaves like Bubble Sort.
 * 
 *  Comb Sort is generally faster than Bubble Sort because it reduces the number of comparisons and swaps.
 * 
 *  Time Complexity:
 *  - Worst Case: O(n^2)
 *  - Average Case: O(n^2)
 *  - Best Case: O(n)
 * 
 *  Space Complexity:
 *  - O(1)
 * 
 * Algorithm:
 * 1. Initialize the gap to the length of the array.
 * 2. While the gap is greater than 1, do the following:
 *    - For each element in the array, compare it with the element that is gap distance apart.
 *    - If the element is in the wrong order, swap them.
 *    - Reduce the gap by the shrink factor.
 * 3. When the gap becomes 1, the algorithm behaves like Bubble Sort.
 */

void comb_sort(int arr[], int n)
{
    int gap;
    for(gap = n / 1.3; gap > 0; gap /= 1.3) {
        int j;
        for(j = gap; j < n; j++){
            if(arr[j] < arr[j - gap]){
                int temp = arr[j];
                arr[j] = arr[j - gap];
                arr[j - gap] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    comb_sort(arr, n);
    printf("After Comb Sort: "); // Expected Result: -44, -6, 0, 1, 3, 4, 8, 23, 28, 56
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}