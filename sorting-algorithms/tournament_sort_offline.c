#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void buildTournament(int tree[], int tree_size, int n){
    int parent;
    for(parent = tree_size / 2 - 1; parent >= 0; parent--){
        int lc = 2 * parent + 1;

        int winner;
        if(lc >= tree_size - n){
            winner = (lc + 1 < tree_size && tree[lc + 1] < tree[lc]) ? lc + 1 : lc;
        } else {
            winner = (tree[tree[lc + 1]] < tree[tree[lc]]) ? tree[lc + 1] : tree[lc];
        }

        tree[parent] = winner;

    }
}

void tournament_sort(int arr[], int n){
    
    int tree_size = 2 * n - 1;
    int tree[tree_size];
    
    int i;
    for(i = 0; i < n; i++){
        tree[tree_size - n + i] = arr[i];
    }
    
    // Original Array Iterator
    int x;
    for(x = 0; x < n; x++){

        buildTournament(tree, tree_size, n);

        arr[x] = tree[tree[0]];
        tree[tree[0]] = INT_MAX;
        
    }
}

int main(){
    int arr[] = {5, 2, 8, 1, 7, 4, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    tournament_sort(arr, n);
    
    printf("Sorted array (Tournament Sort Offline): ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
}
