#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    int *a = (int*) calloc(n, sizeof(int));
    if (a == NULL)
    {
        printf("Memory allocation failed, terminating...\n");
        return 0;
    }
    printf("The array of %d numbers: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int largest = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[largest] < a[i])
            largest = i;
    }
    printf("Largest value: %d\n", a[largest]);
    free(a);
}
