#include <stdio.h>

/**
 *
 * Heap Sort Algorithm
 * 
 * 1. Build a max heap from the array
 * 2. Swap the root of the heap with the last element of the heap
 * 3. Max heapify the root of the heap
 * 4. Repeat steps 2 and 3 until the heap is empty
 * 
 * Description:
 *  This algorithm is a comparison-based sorting algorithm that uses a binary heap data structure.
 *  It is similar to selection sort where we first find the maximum element and place the maximum 
 *  element at the end. We repeat the same process for the remaining elements.
 * 
 */

// Max Heapify Function
void max_heapify(int arr[], int size, int parent);

// Heap Sort Function
void heap_sort(int arr[], int size)
{
    /**
     * Heap Sort Function
     * 
     * Args:
     *  arr[]: The array to be sorted
     *  size: The size of the array
     * 
     */

    int i;
    for(i = (size - 1) / 2 ; i >= 0; i--)
    {
        max_heapify(arr, size, i);
    }

    int lastIdx = size - 1;
    while(lastIdx >= 0)
    {
        int temp = arr[lastIdx];
        arr[lastIdx] = arr[0];
        arr[0] = temp;

        max_heapify(arr, lastIdx--, 0);
    }
}

void max_heapify(int arr[], int size, int parent)
{
    /**
     * Max Heapify Function
     * 
     * Args:
     *  arr[]: The array to be sorted
     *  size: The size of the array
     *  parent: The parent index
     * 
     */

    int lc, child, swapping = 1;

    // Loop until the parent has no children or no swapping is done
    while((lc = 2 * parent + 1) < size && swapping)
    {
        swapping = 0;

        // Find the largest child
        child = (lc + 1 < size && arr[lc + 1] > arr[lc]) ? lc + 1 : lc;

        // Swap if the child is greater than the parent
        if(arr[child] > arr[parent])
        {
            // Swap the parent and child
            int temp = arr[parent];
            arr[parent] = arr[child];
            arr[child] = temp;

            // Continue the loop
            swapping = 1;
            parent = child;
        }
    }
}

int main()
{
    // Sample Array
    int arr[] = {3, 4, 1, 2, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Expected Result, f(arr) = {1, 2, 3, 4, 7, 8}
    heap_sort(arr, size);

    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}