#include <stdio.h>
#include <stdlib.h>
int N;
int **map;

int find_max(int *ar)
{
	int ret = 0;
	int max = -1000000001;
	for(int i = 0; i < N; i ++)
	{
		if(ar[i] > max)
		{
			ret = i;
			max = ar[i];
		}
	}
	return ret;
}
int main()
{
	scanf("%d", &N);
	map = malloc(sizeof(int *) * N);
	for(int i = 0; i < N; i ++)
	{
		map[i] = malloc(sizeof(int) * N);
	}
	for(int i = 0; i < N; i ++)
	{
		for(int j = 0; j < N; j ++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	int tmp_i;
	int tmp_j;
	for(int i = 0; i < N; i ++)
	{
		tmp_j = find_max(map[N-1]);
		if(i == N-1)
			printf("%d", map[N-1][tmp_j]);
		for(int j = 0; j < N; j ++)
		{
			if(map[N-1-j][tmp_j] < map[N-1][tmp_j])
			{
				map[N-1][tmp_j] = map[N-1-j][tmp_j];
				break;
			}
		}
	}
	// for(int i = 0; i < N; i ++)
	// {
	// 	for(int j = 0; j < N; j ++)
	// 	{
	// 		printf("%d ", map[i][j]);
	// 	}
	// 	printf("\n");
	// }
}