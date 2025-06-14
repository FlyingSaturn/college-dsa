#include <stdio.h>
int main(void)
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    int a[n + 1];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int ins;
    printf("Number to insert: ");
    scanf("%d", &ins);
    int op;
    printf("Where to insert?\n1. At the beginning\n2. At any middle position\n3. At the end\nEnter your choice: ");
    scanf("%d", &op);
    int pos = -1;
    switch (op)
    {
        case 1: 
            pos = 0;
            break;
        case 2:
            printf("Enter the position: ");
            scanf("%d", &pos);
            break;
        case 3:
            pos = n;
            break;
        default:
            printf("Invalid case. Program terminating...\n");
            return 0;
    }
    for (int i = n; i > pos; i--)
        a[i] = a[i - 1];
    a[pos] = ins;
    n++;
    printf("Result: ");
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            printf(", ");
        printf("%d", a[i]);
    }
    printf("\n");
}
