#include <stdlib.h>
#include <stdio.h>

#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE
typedef struct s_listnode
{
    int val;
    struct s_listnode *next;
} listnode;
#endif

#ifndef STRUCT_LISTNODE_ARRAY
#define STRUCT_LISTNODE_ARRAY
typedef struct s_listnode_array
{
    int size;
    listnode **array;
} listnode_array;
#endif

void print_list(listnode *head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

listnode *merge_k_sorted_lists(listnode_array *arr)
{
    // Cool stuff happens here
    return NULL;
}

// Create a new list with <length> nodes. Node values increase by linearly based on <interval>
listnode *new_list(int length, int interval) {
    listnode *head = malloc(sizeof(listnode));
    head->val = interval;
    head->next = NULL;

    listnode *tmp;
    listnode *prev = head;
    int i = 1;
    while (i < length) {
        tmp = malloc(sizeof(listnode));
        tmp->val = prev->val + interval;
        prev->next = tmp;
        tmp->next = NULL;
        prev = tmp;
        i += 1;
    }
 
    return (head);
}

int main(void)
{
    listnode_array *arr = malloc(sizeof(listnode_array));
    arr->size = 4;
    arr->array = malloc(arr->size * sizeof(listnode*));

    arr->array[0] = new_list(4, 1); // 1 -> 2 -> 3 -> 4 -> NULL
    print_list(arr->array[0]);

    arr->array[1] = new_list(5, 2); // 2 -> 4 -> 6 -> 8 -> 10 -> NULL
    print_list(arr->array[1]);

    arr->array[2] = new_list(2, 5); // 5 -> 10 -> NULL
    print_list(arr->array[2]);

    arr->array[3] = new_list(4, 3); // 3 -> 6 -> 9 -> 12 -> NULL
    print_list(arr->array[3]);

    printf("Goal:\n");
    printf("Turn the array of sorted linked lists into one long sorted linked list.\n");
    printf("1 -> 2 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5 -> 6 -> 6 -> 8 -> 9 -> 10 -> 10 -> 12 -> NULL\n");

    listnode *result = merge_k_sorted_lists(arr);
    printf("Result:\n");
    print_list(result);

}