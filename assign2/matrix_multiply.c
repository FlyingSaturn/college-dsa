#include <stdio.h>

int main(void)
{
    int m1, n1, m2, n2;
    printf("(Enter the order of the matrix with spaces)\n\nFirst array:- ");
    scanf("%d", &m1);
    scanf("%d", &m2);
    printf("Second array:- ");
    scanf("%d", &n1);
    scanf("%d", &n2);
    if (m2 != n1)
    {
        printf("\nMatrix multiplication not allowed. \nTerminating the program...\n");
        return 0;
    }
    int a[m1][n1], b[m2][n2], c[m1][n2];
    printf("\nEnter the first array: \n");
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nEnter the second array: \n");
    for (int i = 0; i < m2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < m2; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
    printf("\nResultant: \n");
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n2; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
    printf("\n");
}

