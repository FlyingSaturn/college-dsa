#include <stdio.h>

#define SUM (1 + 2 + 3)
// The variable start and target will be in {1, 2, 3}
void hanoi(int n, int start, int target); 

int main(void)
{
	int n;
	printf("No. of disks: ");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("%d disks not possible", n);
		return 0;
	}
	printf("\tDisk\tStart\tTarget\n");
	hanoi(n, 1, 3);
}


void hanoi(int n, int start, int target)
{	
	if (n == 0)
		return;
	hanoi (n - 1, start, SUM - start - target);
	printf("\t%d\t%d\t%d\n", n, start, target);
	hanoi (n - 1, SUM - start - target, target);
}


