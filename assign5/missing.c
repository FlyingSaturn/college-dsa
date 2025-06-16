#include <stdio.h>
int main(void)
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int search;
    printf("Searchable number: ");
    scanf("%d", &search);
    for (int i = 0; i < n; i++)
        if (search == a[i])
        {
            printf("Not a missing element. Position: %d\n", (i + 1));
            return 1;
        }
    printf("Missing element, found nowhere.\n");
}
/*
   1)
n: 5
Enter the array: 1 2 3 4 5
Searchable number: 6
Missing element, found nowhere.

2)
n: 5
Enter the array: 1 2 3 4 5
Searchable number: 3
Not a missing element. Position: 3


*/
