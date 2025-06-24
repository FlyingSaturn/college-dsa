#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

node* create_ll_node(node* head, int d);
void free_ll(node* head);
node* insert(node* head, int d);
node* delete(node* head, int d);
void traverse(node* head);

int main(void)
{
    node* ll = NULL;
    while (1)
    {
        int d, op;
        printf("\nChoices:\n1) Creation (overwrites the existing list)\n2) Insertion\n3) Deletion\n4) Traversal\n5) Exit\nYour choice: ");
        scanf("%d", &op);
        switch (op)
        {
            case 1:
                if (ll != NULL)
                {
                    free_ll(ll);
                    ll = NULL;
                }
                printf("Number to insert: ");
                scanf("%d", &d);
                ll = create_ll_node(ll, d);
                printf("Linked list created!\n");
                break;
            case 2:
                if (ll == NULL)
                {
                    printf("No nodes present.\nPlease create the linked list before proceeding.\n");
                    break;
                }
                printf("Number to insert: ");
                scanf("%d", &d);
                ll = insert(ll, d);
                printf("Insertion done!\n");
                break;
            case 3:
                if (ll == NULL)
                {
                    printf("No nodes present.\nPlease create the linked list before proceeding.\n");
                    break;
                }
                printf("Number to delete (first pass): ");
                scanf("%d", &d);
                ll = delete(ll, d);
                printf("Deletion done!\n");
                break;
            case 4:
                printf("The numbers are: ");
                traverse(ll);
                break;
            case 5:
                printf("Freeing the memory...\t");
                free_ll(ll);
                ll = NULL;
                printf("Freed the memory.\n\nExitting...\n");
                return 0;
            default:
                printf("Invalid choice, please enter the correct option.\n");
        }
    }
}

node* create_ll_node(node* head, int d)
{
    head = (node*) malloc(sizeof(node));
    if (head == NULL)
    {
        printf("Can't alloc. Exitting...\n");
        exit(1);
    }
    head->data = d;
    head->next = NULL;
    return head;
}

// ptr takes over, head moves to next, ptr frees the current
void free_ll(node* head)
{
    while (head != NULL)
    {
        node* ptr = head;
        head = head->next;
        free(ptr);
    }
    head = NULL;
}

node* insert(node* head, int d)
{
    // Making the node
    node* ptr = NULL;
    ptr = create_ll_node(ptr, d);
    // Prepend logic
    ptr->next = head;
    head = ptr;
    return head;
}

node* delete(node* head, int d)
{
    // No nodes? Exit.
    if (head == NULL)
        return head;
    // Traverse till you find
    node* ptr = head;
	node* preptr = NULL;
	while (!(ptr == NULL || ptr->data == d))
	{
		preptr = ptr;
        ptr = ptr->next;
	}
    // Went to the end? Exit. (Related to the while loop)
    if (ptr == NULL)
        return head;
    // Need to delete the start? Go ahead.
    if (ptr == head)
    {
        head = head->next;
        free(ptr);
        return head;
    }
    // Conveniently 'unperson' it
    if (preptr != NULL)
        preptr->next = ptr->next;
    free(ptr);
    return head;
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
