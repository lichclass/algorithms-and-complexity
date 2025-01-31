#include <stdio.h>
#include <stdlib.h>

/**
 * 
 * Strand Sort Algorithm
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

        printf("Current List: ");
        print_list(*list);
        printf("\n");

        insert_last(&sublist, (*list)->value);
        pop(list);

        List *trav = list;
        int last_value = sublist->value;
        while(*trav != NULL)
        {
            if((*trav)->value > last_value)
            {
                last_value = (*trav)->value;
                insert_last(&sublist, (*trav)->value);
                pop(list);
            } else {
                trav = &(*trav)->next;
            }
        }

        printf("Sublist: ");
        print_list(sublist);
        printf("\n");

        merge_sorted(&sublist, result, result);

        printf("Result: ");
        print_list(*result);
        printf("\n\n");

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
        *list = (*list)->next;
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
        if((*aptr)->value < (*bptr)->value)
        {
            *cptr = *aptr;
            *aptr = (*aptr)->next;
        }
        else 
        {
            *cptr = *bptr;
            *bptr = (*bptr)->next;
        }
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
    insert_last(&list, 3);
    insert_last(&list, 2);
    insert_last(&list, 1);
    strand_sort(&list, &result);

    printf("Sorted List: ");
    print_list(result);
    printf("\n");


    return 0;
}
