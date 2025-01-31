#include <stdio.h>
#include <stdlib.h>

/**
 * 
 * Strand Sort Algorithm
 * 
 * 1. Create a sublist and initialize it to NULL
 * 2. Traverse the original list and insert the current node into the sublist
 * 3. Traverse the original list and check if the current node is greater than the last node of the sublist
 * 4. If it is, insert the current node into the sublist
 * 5. If it is not, move to the next node
 * 6. Merge the sublist with the original list
 * 7. Repeat the process until the original list is empty
 * 
 * Description:
 *  This algorithm is a comparison-based sorting algorithm that uses a sublist to sort the original list.
 *  It is a variation of the merge sort algorithm.
 * 
 */

typedef struct node {
    int value;
    struct node *next;      
} *List;

// Required Functions
void init_list(List *list);   
void insert_last(List *list, int value);
void pop(List *list);
void merge_sorted(List *listA, List *listB, List *result);

// Utility Functions
void free_list(List *list);
void print_list(List list);

void strand_sort(List *list, List *result)
{
    if(*list != NULL)
    {
        List sublist;
        init_list(&sublist);

        // printf("Current List (before): ");
        // print_list(*list);
        // printf("\n");

        insert_last(&sublist, (*list)->value);
        pop(list);

        // printf("Current List (after): ");
        // print_list(*list);
        // printf("\n");

        // printf("Sublist (before): ");
        // print_list(sublist);
        // printf("\n");

        List *trav = list;
        int last_value = sublist->value;
        while(*trav != NULL)
        {
            // if((*trav)->value > last_value) // For ascending order
            if((*trav)->value > last_value)
            {
                last_value = (*trav)->value;
                insert_last(&sublist, last_value);
                pop(trav);
            } else {
                trav = &(*trav)->next;
            }
        }

        // printf("Sublist (after): ");
        // print_list(sublist);
        // printf("\n");

        merge_sorted(&sublist, result, result);

        // printf("Result: ");
        // print_list(*result);
        // printf("\n\n");

        if(*list != NULL)
        {
            strand_sort(list, result);
        }
    }
    
}

void init_list(List *list)  
{
    *list = NULL;
}

void insert_last(List *list, int value)
{
    List new_node = (List)malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;

    // Insert at the end of the list
    List *temp;
    for(temp = list; *temp != NULL; temp = &(*temp)->next);
    *temp = new_node;
}

void pop(List *list)
{
    if(*list != NULL)
    {
        List temp = *list;
        *list = temp->next;
        free(temp);
    }
}

void merge_sorted(List *listA, List *listB, List *result)
{
    List *aptr = listA;
    List *bptr = listB;

    List merged;
    init_list(&merged);
    List *cptr = &merged;

    while(*aptr != NULL && *bptr != NULL)
    {
        *cptr = (*aptr)->value < (*bptr)->value ? *aptr : *bptr;
                (*aptr)->value < (*bptr)->value ? (*aptr = (*aptr)->next) : (*bptr = (*bptr)->next);
        cptr = &(*cptr)->next;
    }

    *cptr = (*aptr != NULL) ? *aptr : *bptr;

    *result = merged;
}
    
void free_list(List *list)
{
    while(*list != NULL)
    {
        pop(list);
    }
}

void print_list(List list)
{
    while(list != NULL)
    {
        printf("%d ", list->value);
        list = list->next;
    }
}

int main()
{
    List list; init_list(&list);
    List result; init_list(&result);

    insert_last(&list, 5);
    insert_last(&list, 4);
    insert_last(&list, 7);
    insert_last(&list, 6);
    insert_last(&list, 2);
    insert_last(&list, 1);
    strand_sort(&list, &result);

    printf("Sorted List: ");
    print_list(result);
    printf("\n");


    return 0;
}
