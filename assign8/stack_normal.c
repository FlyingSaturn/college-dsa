#include <stdio.h>
#define MAX 5

void push(int data);
int pop();
void display();
int peek();

int a[MAX];
int top = -1;

int main(void)
{
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

void push(int data)
{
    if (top >= MAX - 1)
    {
        printf("Stack overflow.\n");
            return;
    }
    a[++top] = data;
}

int pop()
{
    if (top < 0)
    {
        printf("Stack underflow.\n");
        return -1;
    }
    int popped = a[top--];
    return popped;
}

void display()
{
    if (0 > top)
        printf("Nothing to show.\n");
    else
    {
        int i = top;
        while (i >= 0)
        {
            if (i != top)
                printf(", ");
            printf("%d", a[i]);
            i--;
        }
        printf("\n");
    }
}

int peek()
{
    if (top < 0)
    {
        printf("No elements to show.\n"); 
        return -1;
    }
    return a[top];
}


