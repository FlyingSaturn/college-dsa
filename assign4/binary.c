#include <stdio.h>

int binary_recurse(int a[], int s, int low, int high);
int binary_iter(int a[], int s, int n); 

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

    int d, op = -1;
    while (!(op >= 1 && op <= 3))
    {
        printf("How do you want your results?\n1. Recursion\n2. Iteration\n3. Both\nEnter your choice: ");
        scanf("%d", &op);
        switch(op)
        {
            case 1:
                d = binary_recurse(a, s, 0, n - 1);
                if (d == -1)
                    printf("Number not found.\n");
                else
                    printf("Number found! Position: %d\n", d);
                break;
            case 2:
                d = binary_iter(a, s, n);
                if (d == -1)
                    printf("Number not found.\n");
                else
                    printf("Number found! Position: %d\n", d);
                break;
            case 3:
                printf("==Using Recursion==\n");
                d = binary_recurse(a, s, 0, n - 1);
                if (d == -1)
                    printf("Number not found.\n");
                else
                    printf("Number found! Position: %d\n", d);
                printf("\n==Using Iteration==\n");
                d = binary_iter(a, s, n);
                if (d == -1)
                    printf("Number not found.\n");
                else
                    printf("Number found! Position: %d\n", d);
                break;
            default:
                printf("Invalid case, please try again.\n");
        }

    }
}


    int binary_recurse(int a[], int s, int low, int high)
    {
        if (low > high)
            return -1;
        int p = (low + high) / 2;
        if (a[p] < s)
            return binary_recurse(a, s, p + 1, high);
        if (a[p] > s)
            return binary_recurse(a, s, low, p - 1);
        if (a[p] == s)
            return p;
    }

    int binary_iter(int a[], int s, int n)
    {
        int low = 0, high = n - 1, p = 0;
        while (low <= high)
        {
	    p = (low + high) / 2;
            if (a[p] < s)
                low = p + 1;
            if (a[p] > s)
                high = p - 1;
            if (a[p] == s)
                return p;
        }
        return -1;
    }
