#include <stdio.h>
#include <stdlib.h>

void print_answer(int **array)
{
	int i, j, x, y;
	int sum = 0;
	scanf("%d %d %d %d", &i, &j, &x, &y);
	for(int tmp = 0; x - i - tmp >= 0; tmp ++)
	{
		for(int tmp2 = 0; y - j - tmp2 >= 0; tmp2 ++)
		{
			sum += array[i + tmp - 1][j + tmp2 - 1];
		}
	}
	printf("%d\n", sum);
}

int main()
{
	int N, M, K;
	char *s;
	scanf("%d", &N);
	scanf("%d", &M);
	int **array = malloc(sizeof(int *) * N);
	for(int i = 0; i < N; i ++)
	{
		array[i] = malloc(sizeof(int) * M);
	}
	for(int i = 0; i < N; i ++)
	{
		for(int j = 0; j < M; j ++)
		{
			scanf("%d", &array[i][j]);
		}
	}
	scanf("%d", &K);
	for(int i = 0; i <K; i ++)
	{
		print_answer(array);
	}
}