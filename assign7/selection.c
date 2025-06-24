#include <stdio.h>

int main(void)
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    int a[n];
    printf("The array of %d numbers: ", n);
    for (int i = 0; i < n; i++)
       scanf("%d", &a[i]);
    for(int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[min] > a[j])
                min = j;
        int t = a[i];
        a[i] = a[min];
        a[min] = t;
    }
    printf("The final array: ");
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            printf(", ");
        printf("%d", a[i]);
    }
    printf("\n");
}
