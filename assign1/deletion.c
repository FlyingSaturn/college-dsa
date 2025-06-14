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
    int del;
    printf("Postion to delete from: ");
    scanf("%d", &del);
    for (int i = del + 1; i < n; i++)
        a[i - 1] = a[i];
    n--;
    printf("Result: ");
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            printf(", ");
        printf("%d", a[i]);
    }
    printf("\n");
}
