#include <stdio.h>

int main(void)
{
	int m, n;
	printf("m: ");
	scanf("%d", &m);
	printf("n: ");
	scanf("%d", &n);
	int k = 1;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", k++);
		printf("\n");
	}
}
