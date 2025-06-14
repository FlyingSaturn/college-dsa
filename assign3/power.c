#include <stdio.h>

double power(double x, int n);

int main(void)
{
    int n; double x;
    printf("Base: ");
    scanf("%lf", &x);
    printf("Exponent: ");
    scanf("%d", &n);
    if (x == 0 && n == 0)
    {
        printf("Indeterminate result.\n");
        return 0;
    }
    double res = power(x, n);
    printf("Resultant: %lf\n", res);
}


double power(double x, int n)
{
    if (x == 0)
        return 0.0;
    if (n == 0)
        return 1.0;
    return x * power(x, n - 1);
}

