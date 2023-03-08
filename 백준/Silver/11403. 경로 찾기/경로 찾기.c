#include <stdio.h>
#include <stdlib.h>

int N;
int **map;

int **answer_map;

void recursive_find(int row, int *answer_map)
{
	for(int i = 0; i < N; i ++)
	{
		if(map[row][i] == 1 && answer_map[i] == 0)
		{
			answer_map[i] = 1;
			recursive_find(i, answer_map);
		}
	}
}

void make_answer_by_row()
{
	for(int i = 0; i < N; i ++)
	{
		recursive_find(i, answer_map[i]);
	}
}

int main()
{
	scanf("%d", &N);
	map = malloc(sizeof(int *) * N);
	answer_map = malloc(sizeof(int *) * N);
	for(int i = 0; i < N; i ++)
	{
		map[i] = malloc(sizeof(int) * N);
		answer_map[i] = malloc(sizeof(int) * N);
	}
	for(int i = 0; i < N; i ++)
	{
		for(int j = 0; j < N; j ++)
		{
			scanf(" %d", &map[i][j]);
			answer_map[i][j] = 0;
		}
	}

	make_answer_by_row();
	for(int i = 0; i < N; i ++)
	{
		for(int j = 0; j < N; j ++)
		{
			printf("%d ", answer_map[i][j]);
		}
		printf("\n");
	}
}