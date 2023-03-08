#include <stdio.h>
#include <stdlib.h>

int N;
int rope[100000];

int compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i ++)
		scanf(" %d", rope + i);
	qsort(rope, N, sizeof(int), compare);
	// for(int i = 0; i < N; i ++)
	// 	printf(" %d", rope[i]);
	// printf("\n");
	int max = -1;
	for(int i = 1; i <= N; i ++)
	{
		if(max < rope[N - i] * i)
			max = rope[N - i] * i;
	}
	printf("%d\n", max);
}