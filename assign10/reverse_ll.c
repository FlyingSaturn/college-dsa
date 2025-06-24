#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

node* ll = NULL;

void insert_ll(int d);
void display_ll();
void free_ll();

int main(void)
{
    int n;
    node* ll;
    printf("n: ");
    scanf("%d", &n);
    int a[n];
    printf("The %d numbers: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        insert_ll(a[i]);
    printf("The reversed numbers are: ");
    display_ll();
    printf("\n");
    free_ll();
}


void insert_ll(int d)
{
    node* ptr = (node*) malloc(sizeof(node));
    ptr->data = d;
    ptr->next = NULL;
    if (ll == NULL)
    {
        ll = ptr;
        return;
    }
    ptr->next = ll;
    ll = ptr;
}

void display_ll()
{
    node* ptr = ll;
    if (ptr == NULL)
    {
        printf("None.");
        return;
    }
    while (ptr != NULL)
    {
        if (ptr != ll)
            printf(", ");
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
}

void free_ll()
{
    node* ptr = NULL;
    if (ptr == NULL)
        return;
    while (ll != NULL)
    {
        ptr = ll;
        ll = ll->next;
        free(ptr);
    }
}
