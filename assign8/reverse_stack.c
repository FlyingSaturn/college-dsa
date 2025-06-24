#include <stdio.h>

int main(void)
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    int a[n], d, top = -1;
    printf("The %d numbers: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d);
        a[++top] = d;
    }
    printf("The reversed numbers are: ");
    for (int i = top; i >= 0; i--)
    {
        if (top != i)
            printf(", ");
        printf("%d", a[i]);
    }
    printf("\n");
}
