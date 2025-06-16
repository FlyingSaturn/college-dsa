#include <stdio.h>

int main(void)
{
    int m, n, k = 0;
    printf("m: ");
    scanf("%d", &m);
    printf("n: ");
    scanf("%d", &n);
    int a[m][n];
    printf("Enter the full array: \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0)
                k++;
        }
    }
    int b[k][3];
    int c = 0;
    for (int i = 0; i < m; i++)
    {  
        for (int j = 0; j < n; j++)
            if(a[i][j] != 0)
            {
                b[c][0] = i;
                b[c][1] = j;
                b[c++][2] = a[i][j];
            }
    }
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < k; i++)
    {  
        printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
    }
}
/*  
m: 4 
n: 4 
Enter the full array: 
0 0 1 0
0 2 0 0 
0 0 0 5
0 3 0 4
Row    Column    Value
0    2    1
1    1    2
2    3    5
3    1    3
3    3    4    
*/
