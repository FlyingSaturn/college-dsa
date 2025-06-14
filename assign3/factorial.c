#include <stdio.h>

long fact(int x);

int main(void)
{
    int x;
    printf("x: ");
    scanf("%d", &x);
    if (x < 0)
    {
        printf("Negative factorial doesn't exist.\n");
        return 0;
    }
    long res = fact(x);
    printf("Resultant: %ld\n", res);
}


long fact(int x)
{
    if (x == 0 || x == 1)
        return 1;
    return x * fact(x - 1);
}

