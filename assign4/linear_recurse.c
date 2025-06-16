include <stdio.h>

int linear_search(int a[], int s, int current, int n);

int main(void)
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    int a[n];
    printf("The array of %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int s;
    printf("No. to search: ");
    scanf("%d", &s);
    int d = linear_search(a, s, 0, n);
    if (d == -1)
        printf("Number not found.\n");
    else
        printf("Number found! Position: %d\n", d);
}


int linear_search(int a[], int s, int current, int n)
{
    if (a[current] == s)
        return current;
    if (current >= n)
        return -1;
    return linear_search(a, s, ++current, n);
}
