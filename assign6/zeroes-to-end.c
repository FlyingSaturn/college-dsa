#include <stdio.h>
#include <stdlib.h>

void insertion(int* a, int n);
void two_pointers(int* a, int n);

int main(void)
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    int* a = calloc(n, sizeof(int));
    printf("The array with multiple zeroes: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    two_pointers(a, n);
    printf("Array elements:\n");
    for (int i = 0; i < n; i++)
        printf("%d\n", a[i]);
}

void insertion(int* a, int n)
{
    for (int i = n - 2; i >= 0; i--)
    {
        int key = a[i];
        if (key != 0)
            continue;

        int j = i + 1;
        while (j <= n - 1 && a[j] != key)
        {
                a[j - 1] = a[j];
                j++;
        }
        a[j - 1] = key;
    }
}

// Pushing non-zeroes to the left
void two_pointers(int* a, int n)
{
    int last_zero = -1;
    for (int i = 0; i < n; i++)
    {
        if (last_zero == -1)
        {
            if (a[i] == 0)
                last_zero = i;
            continue;
        }
        if (a[i] != 0)
        {
            int t = a[last_zero];
            a[last_zero] = a[i];
            a[i] = t;
            last_zero++;
        }
    }
}
