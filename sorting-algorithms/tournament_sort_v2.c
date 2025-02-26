#include <stdio.h>
#include <stdlib.h>   // for qsort, etc.
#include <limits.h>

int compare(const void *x, const void *y) {
    int a = *(const int *)x;
    int b = *(const int *)y;
    return (a - b);
}

void buildTournament(int tree[]){
    for(int i = 2; i >= 0; i--){
        int lc = 2 * i + 1;
        int winner;
        if(i > 0){
            winner = (tree[lc + 1] < tree[lc]) ? lc + 1 : lc;
        } else {
            winner = (tree[tree[lc + 1]] < tree[tree[lc]]) ? tree[lc + 1] : tree[lc];
        }

        tree[i] = winner;
    }
}

void tournament_sort(int arr[], int n){
    // If fewer than 4 elements, just do a normal qsort
    if(n < 4){
        qsort(arr, n, sizeof(int), compare);
        return;
    }

    int tree_size = 7;
    int tree[tree_size];

    // 1) Load the first 4 elements of arr into leaves [3..6]
    for(int i = 3; i < tree_size; i++){
        tree[i] = arr[i - 3];
    }

    // 2) Build the initial tournament
    buildTournament(tree);

    // 3) Extract winners and replace them with new elements (or INT_MAX)
    for(int i = 0; i < n; i++){
        // The index of the winning leaf is tree[0].
        // The winner's *value* is tree[ tree[0] ].
        arr[i] = tree[ tree[0] ];

        // If we still have a "next" element (arr[i+4]) available, use it;
        // otherwise, set that leaf to INT_MAX so it won't win again.
        if(i < n - 4){
            tree[ tree[0] ] = arr[i + 4];
        } else {
            tree[ tree[0] ] = INT_MAX;
        }

        // Rebuild to find the next winner
        buildTournament(tree);
    }

    // 4) Finally, do a qsort to ensure the entire array is sorted
    qsort(arr, n, sizeof(int), compare);
}

int main(){
    int arr[] = {5, 2, 8, 1, 7, 4, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    tournament_sort(arr, n);
    
    printf("Sorted array (Tournament Sort v1): ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
