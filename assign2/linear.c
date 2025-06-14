#include <stdio.h>

int main(void)
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    int a[n];
    printf("The array of %d numbers: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int searchable;
    printf("Searchable number: ");
    scanf("%d", &searchable);
    for (int i = 0; i < n; i++)
        if (a[i] == searchable)
        {
            printf("Number found! Position: %d\n", i);
            return 0;
        }
    printf("Number not found.\n");
}

