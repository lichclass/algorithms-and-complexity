#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} *List;

void init_list(List *list);
void append(List *list, int value);
void pop(List *list);
void free_list(List *list);
void print_list(List list);

void strand_sort(List *list, List *result)
{
    if(*list == NULL) // Base Case: Empty list
    {
        return;
    }

    if ((*list)->next == NULL) // Base Case: Single element
    {
        append(result, (*list)->value);
        return;
    }

    // Create a sub-array of increasing elements
    List sub_array;
    init_list(&sub_array);

    // Add the first element to the sub-array
    append(&sub_array, (*list)->value);
    pop(list);

    // Add the remaining elements to the sub-array
    List *temp;
    int sub_array_last_value = sub_array->value;
    for(temp = *list; *temp != NULL; temp = &(*temp)->next)
    {
        if((*temp)->value > sub_array_last_value)
        {
            sub_array_last_value = (*temp)->value; // Update the last value of the sub-array
            append(&sub_array, (*temp)->value); // Add the element to the sub-array
            pop(temp); // Remove the element from the list
        }
    }

    // Merge the sub-array with the result
    List *aptr = sub_array;
    while(*aptr != NULL)
    {
        append(result, (*aptr)->value);
        pop(aptr);
    }

    // Free the sub-array
    free_list(&sub_array);

    // Recursively sort the remaining list
    strand_sort(list, result);
}

void init_list(List *list)
{
    *list = NULL;
}

void append(List *list, int value)
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
    List list, result;
    init_list(&list);
    init_list(&result);

    append(&list, 5);
    append(&list, 3);
    append(&list, 1);
    append(&list, 4);
    append(&list, 2);

    // Expected output: 1 2 3 4 5

    printf("Original list: ");
    print_list(list);
    printf("\n");

    strand_sort(list, result);

    printf("Sorted list: ");
    print_list(result);
    printf("\n");

    free_list(&list);
    free_list(&result);

    return 0;
}

