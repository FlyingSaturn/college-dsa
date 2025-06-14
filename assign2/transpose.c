#include <stdio.h>

int main(void)
{
    int m, n;
    printf("m: ");
    scanf("%d", &m);
    printf("n: ");
    scanf("%d", &n);
    int a[m][n], b[n][m];
    printf("The matrix of %d x %d:\n", m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            b[j][i] = a[i][j];
    printf("\nThe transposed matrix: \n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d\t", b[i][j]);
        printf("\n");
    }
}
