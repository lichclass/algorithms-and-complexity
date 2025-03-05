/**
 * 
 * Strand Sort Algorithm Linked List Version
 * 
 * Description:
 *  This algorithm is a comparison-based sorting algorithm that uses a sublist to sort the original list.
 *  It is a variation of the merge sort algorithm.
 * 
 * Time Complexity
 *  - Worst Case: O(n^2)
 *  - Average Case: O(n^2)
 *  - Best Case: O(n)
 * 
 * Space Complexity
 *  - O(1) in-place due to simply rearranging the linked list
 * 
 * Algorithm:
 *  1. Create a sublist and initialize it to NULL
 *  2. Traverse the original list and insert the current node into the sublist
 *  3. Traverse the original list and check if the current node is greater than the last node of the sublist
 *  4. If it is, insert the current node into the sublist
 *  5. If it is not, move to the next node
 *  6. Merge the sublist with the original list
 *  7. Repeat the process until the original list is empty
 * 
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;      
} *List;

// These are just utilities
void insert_last(List *list, int value); // For easy link list initialization
void print_list(List list); // For printing

// Actual Functions needed
void merge_sorted(List *sublist, List *output);
void strand_sort(List *list);

void merge_sorted(List *sublist, List *output) {
    List merged = NULL;
    List *cptr = &merged;

    while (*sublist != NULL && *output != NULL) {
        if ((*sublist)->value < (*output)->value) {
            *cptr = *sublist;
            *sublist = (*sublist)->next;
        } else {
            *cptr = *output;
            *output = (*output)->next;
        }
        cptr = &(*cptr)->next;
    }

    *cptr = (*sublist != NULL) ? *sublist : *output;
    *output = merged;
}

void strand_sort(List *list) {
    List output = NULL; 

    while (*list != NULL) {

        // Initialize the sublist
        List sublist = NULL;
        List *subPtr = &sublist;

        // Extract first element from list
        List temp = *list;
        *list = temp->next;
        *subPtr = temp;
        temp->next = NULL;
        subPtr = &(*subPtr)->next;

        // Important: Store the last value of the sublist
        int last_value = sublist->value;

        List *trav = list;
        while (*trav != NULL) {
            // Check if next element is greater than last element of sublist
            if ((*trav)->value > last_value) { 
                temp = *trav;
                *trav = temp->next;

                *subPtr = temp;
                last_value = temp->value;

                temp->next = NULL;
                subPtr = &(*subPtr)->next;
            } else {
                trav = &(*trav)->next;
            }
        }

        merge_sorted(&sublist, &output);  // Merge sublist into the output
    }

    *list = output; // Replace the original list with the sorted list
}

int main() {
    List list; 
    init_list(&list);

    insert_last(&list, 3);
    insert_last(&list, 9);
    insert_last(&list, 1);
    insert_last(&list, 7);
    insert_last(&list, 3);
    insert_last(&list, 2);
    insert_last(&list, 8);
    insert_last(&list, 4);

    strand_sort(&list);

    printf("Sorted List: ");
    print_list(list);

    return 0;
}


void print_list(List list) {
    while (list != NULL) {
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
}

void insert_last(List *list, int value) {
    List new_node = (List)malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;

    List *temp;
    for (temp = list; *temp != NULL; temp = &(*temp)->next);
    *temp = new_node;
}
