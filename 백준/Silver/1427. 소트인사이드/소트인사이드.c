#include <stdio.h>
#include <stdlib.h>

int N;
int numset[10];

int compare(const void *a, const void *b)
{
	return (*(int *)b) - (*(int *)a);
}

int main()
{
	scanf("%d", &N);
	if(N == 0)
	{
		printf("0");
		return 0;
	}
	int i = 0;
	while(N != 0)
	{
		numset[i] = N % 10;
		N = N / 10;
		i ++;
	}
	qsort(numset, i, sizeof(int), compare);
	for(int j = 0; j < i; j ++)
		printf("%d", numset[j]);
}