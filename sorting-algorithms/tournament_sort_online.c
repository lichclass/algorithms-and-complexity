#include <stdio.h>
#include <stdlib.h>  
#include <limits.h>

void shell_sort(int arr[], int n){
    int i, j, gap, key;
    for(gap = n; gap > 0; gap /= 2){
        for(i = gap; i < n; i++){
            key = arr[i];
            for(j = i; j >= gap && arr[j - gap] > key; j -= gap){
                arr[j] = arr[j - gap];
            }
            arr[j] = key;
        }
    }
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
    // If fewer than 4 elements, just do a normal sort
    if(n < 4){
        shell_sort(arr, n);
        return;
    }

    int tree_size = 7;
    int tree[tree_size];

    // 1) Load the first 4 elements of arr into leaves [3..6]
    for(int i = 3; i < tree_size; i++){
        tree[i] = arr[i - 3];
    }

    // 2) Build the tournament tree
    for(int i = 0; i < n; i++){
        buildTournament(tree);
        arr[i] = tree[ tree[0] ];

        if(i < n - 4){
            tree[ tree[0] ] = arr[i + 4];
        } else {
            tree[ tree[0] ] = INT_MAX;
        }
    }

    // 3) Sort the elements using your algorithm of choice
    shell_sort(arr, n);
}

int main(){
    int arr[] = {5, 2, 8, 1, 7, 4, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    tournament_sort(arr, n);
    
    printf("Sorted array (Tournament Sort Online): ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
