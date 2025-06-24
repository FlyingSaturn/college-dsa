#include <stdio.h>
#define MAX 5

void initialize();
void push(int data);
int pop();
void display();
int peek();

int a[MAX];
int* top;

int main(void)
{
    initialize();
    int op;
    while (1)
    {
        printf("Enter an option:\n 1. Push\n 2. Pop\n 3. Peek\n 4. Display\n 5. Exit\n\nEnter your option: ");
        scanf("%d", &op);
        int abc;
        switch(op)
        {
            case 1:
                printf("Enter the number: ");
                scanf("%d", &abc);
                push(abc);
                break;
            case 2:
                abc = pop();
                printf("Popped out element: %d\n", abc);
                break;
            case 3:
                abc = peek();
                printf("Topmost element: %d\n", abc);
                break;
            case 4:
                display();
                break;
            case 5:
                break;
            default:
                printf("Invalid case. Please try again.\n");
        }
        if (op == 5)
            break;
    }
    printf("Program terminated.\n\n\n");
}
void initialize()
{
    top = a - 1;
}

void push(int data)
{
    if (top >= a + MAX - 1)
    {
        printf("Stack overflow.\n");
            return;
    }
    *(++top) = data;
}

int pop()
{
    if (top < a)
    {
        printf("Stack underflow.\n");
        return -1;
    }
    int popped = *(top--);
    return popped;
}

void display()
{
    int* ptr = top;
    if (a > top)
        printf("Nothing to show.\n");
    else
    {
        int i = 0;
        while (ptr >= a)
        {
            if (ptr != top)
                printf(", ");
            printf("%d", *ptr);
            i++;
            ptr--;
        }
        printf("\nNo. of elements: %d\n", i);
    }
}

int peek()
{
    if (top < a)
    {
        printf("No elements to show.\n"); 
        return -1;
    }
    return *top;
}


