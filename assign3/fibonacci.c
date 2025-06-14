#include <stdio.h>

int fib(int term, int first, int second);

int main(void)
{
    int t;
    printf("Term (from 0): ");
    scanf("%d", &t);
    if (t < 0)
    {
        printf("Negative term is invalid.\n");
        return 0;
    }
    printf("Fibonacci numbers till F_%d:\n", t);
    fib(t, 0, 1);
}


int fib(int term, int first, int second)
{
    // returned value not to be read
    if (term < 0)
        return -1;

    printf("%d\n", first);
    fib(term - 1, second, first + second);
}

