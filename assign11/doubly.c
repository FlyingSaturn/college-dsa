#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
} node;

void create_dll_node(node** head, int d);
void free_dll(node** head);
void insert(node** head, int d);
void delete(node** head, int d);
void traverse(node* head);

int main(void)
{
    node* dll = NULL;
    while (1)
    {
        int d, op;
        printf("\nChoices:\n1) Creation (overwrites the existing list)\n2) Insertion\n3) Deletion\n4) Traversal\n5) Exit\nYour choice: ");
        scanf("%d", &op);
        switch (op)
        {
            case 1:
                if (dll != NULL)
                    free_dll(&dll);
                printf("Number to insert: ");
                scanf("%d", &d);
                create_dll_node(&dll, d);
                printf("Doubly linked list created!\n");
                break;
            case 2:
                if (dll == NULL)
                {
                    printf("No nodes present.\nPlease create the linked list before proceeding.\n");
                    break;
                }
                printf("Number to insert: ");
                scanf("%d", &d);
                insert(&dll, d);
                printf("Insertion done!\n");
                break;
            case 3:
                if (dll == NULL)
                {
                    printf("No nodes present.\nPlease create the linked list before proceeding.\n");
                    break;
                }
                printf("Number to delete (first pass): ");
                scanf("%d", &d);
                delete(&dll, d);
                printf("Deletion done!\n");
                break;
            case 4:
                printf("The numbers are: ");
                traverse(dll);
                break;
            case 5:
                printf("Freeing the memory...\t");
                free_dll(&dll);
                printf("Freed the memory.\n\nExitting...\n");
                return 0;
            default:
                printf("Invalid choice, please enter the correct option.\n");
        }
    }
}

void create_dll_node(node** head, int d)
{
    *head = (node*) malloc(sizeof(node));
    if (*head == NULL)
    {
        printf("Can't alloc. Exitting...\n");
        exit(1);
    }
    (*head)->data = d;
    (*head)->prev = NULL;
    (*head)->next = NULL;
}

// ptr takes over, head moves to next, ptr frees the current
void free_dll(node** head)
{
    while (*head != NULL)
    {
        node* ptr = *head;
        *head = (*head)->next;
        free(ptr);
    }
    *head = NULL;
}

void insert(node** head, int d)
{
    // Making the node
    node* ptr = NULL;
    create_dll_node(&ptr, d);
    // Prepend logic
    ptr->next = *head;
    (*head)->prev = ptr;
    *head = ptr;
}

void delete(node** head, int d)
{
    // No nodes? Exit.
    if (*head == NULL)
        return;
    // Traverse till you find
    node* ptr = *head;
    while (!(ptr == NULL || ptr->data == d))
        ptr = ptr->next;
    // Went to the end? Exit.
    if (ptr == NULL)
        return;
    // Need to delete the start? Go ahead.
    if (ptr == *head)
    {
        *head = (*head)->next;
        free(ptr);
        return;
    }
    // Conveniently 'unperson' it
    if (ptr->prev != NULL)
        ptr->prev->next = ptr->next;
    if (ptr->next != NULL)
        ptr->next->prev = ptr->prev;
    free(ptr);
}

void traverse(node* head)
{
    if (head == NULL)
    {
        printf("None.\n");
        printf("Please create the list before traversing.\n");
        return;
    }
    node* ptr = head;
    while (ptr != NULL)
    {
        if (ptr != head)
            printf(", ");
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
