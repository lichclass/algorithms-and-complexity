/**
 * 
 * Bucket Sort Algorithm (Non-negative)
 * 
 * Description:
 *  Bucket sort is a sorting algorithm that is based on the concept of buckets.
 *  It works by grouping the elements of the array into buckets based on their value.
 *  Then, it sorts each bucket individually. (Geeks for Geeks, 2025)
 * 
 *  Time Complexity:
 *   - Worst Case: O(n^2)
 *   - Average Case: O(n + k)
 *   - Best Case: O(n + k)
 * 
 *  Space Complexity:
 *   - Worst Case: O(n)
 *   - Average Case: O(n)
 *   - Best Case: O(n)
 * 
 *  Algorithm:
 *   1. Find the largest and smallest number in the array.
 *   2. Find the number of buckets.
 *   3. Find the range of the buckets.
 *   4. Initialize the buckets.
 *   5. Insert the elements into the buckets. 
 *      - Sort the Elements in Each Bucket using Insert Sorted
 *   6. Transfer the elements from the buckets to the original array.
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct list {
    int data;
    struct list *next;
} *List;

void bucket_sort(int arr[], int n) {

    int largest;
    int smallest;

    // Get the amount of buckets
    int no_buckets = sqrt(n);
    
    // Find the largest number
    largest = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }

    // // Find the smallest number
    smallest = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] < smallest){
            smallest = arr[i];
        }
    }

    // // Range of the buckets
    int range = (largest - smallest) / no_buckets + 1;


    // Initialize the buckets
    List buckets[no_buckets];
    for(int i = 0; i < no_buckets; i++){
        buckets[i] = NULL;
    }

    // Insert the elements into the buckets
    for(int i = 0; i < n; i++){
        int idx = (arr[i] - smallest) / range;

        // Insert Sorted
        List *trav;
        for(trav = &buckets[idx]; *trav != NULL && (*trav)->data <= arr[i]; trav = &(*trav)->next){}

        List temp = (List)malloc(sizeof(struct list));
        temp->data = arr[i];
        temp->next = *trav;
        *trav = temp;
    }

    // Transfer the elements from the buckets to the original array
    int idx = 0;
    for(int i = 0; i < no_buckets; i++){
        List *trav = &buckets[i];
        while(*trav != NULL){
            arr[idx++] = (*trav)->data;
            trav = &(*trav)->next;
        }
    }
    
}

int main() {

    int arr[] = {88, 99, 23, 45, 95, 77, 67, 90, 41, 35, 58, 80, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}