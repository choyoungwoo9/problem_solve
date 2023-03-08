#include <stdio.h>
#include <unistd.h>

int N, M;
int input_map[8][8];
int copied_map[8][8];

int max = 0;

void copy_map()
{
	for(int i = 0; i < N; i ++)
	{
		for(int j = 0; j < M; j ++)
		{
			copied_map[i][j] = input_map[i][j];
		}
	}
}

void virus_dfs(int i , int j)
{
 	if(copied_map[i][j] == 3)
		return ;
	copied_map[i][j] = 3;
	int dx[4] = {-1, 0, 0, 1};
	int dy[4] = {0, 1, -1, 0};
	for(int k = 0; k < 4; k ++)
	{
		if(i + dy[k] < 0 || i + dy[k] >= N || j + dx[k] < 0 || j+dx[k] >= M)
			continue;
		if(copied_map[i+dy[k]][j+dx[k]] == 0 || copied_map[i+dy[k]][j+dx[k]] == 2)
			virus_dfs(i+dy[k], j+dx[k]);
	}
}

void safe_dfs(int i , int j, int *answer)
{
	if(copied_map[i][j] == 1)
		return ;
	copied_map[i][j] = 1;
	(*answer) ++;
	int dx[4] = {-1, 0, 0, 1};
	int dy[4] = {0, 1, -1, 0};
	for(int k = 0; k < 4; k ++)
	{
		if(i + dy[k] < 0 || i + dy[k] >= N || j + dx[k] < 0 || j+dx[k] >= M)
			continue;
		if(copied_map[i+dy[k]][j+dx[k]] == 0)
			safe_dfs(i+dy[k], j+dx[k], answer);
	}
}

void find_answer()
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j ++)
		{
			if(copied_map[i][j] == 2)
				virus_dfs(i, j);
		}
	}
	int answer = 0;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j ++)
		{
			if(copied_map[i][j] == 0)
				safe_dfs(i, j, &answer);
		}
	}
	if(answer > max)
		max = answer;
}

void made_second_wall(int first_i, int first_j, int second_i, int second_j)
{
	for(int i = second_i; i < N; i ++)
	{
		for(int j = 0; j < M; j ++)
		{
			if(i == second_i && j <= second_j)
				continue;
			if(input_map[i][j] == 0)
			{
				copy_map();
				copied_map[first_i][first_j] = 1;
				copied_map[second_i][second_j] = 1;
				copied_map[i][j] = 1;
				find_answer();
			}
		}
	}
}

void made_first_wall(int first_i, int first_j)
{
	for(int i = first_i; i < N; i ++)
	{
		for(int j = 0; j < M; j ++)
		{
			if(i == first_i && j <= first_j)
				continue;
			if(input_map[i][j] == 0)
				made_second_wall(first_i, first_j, i, j);
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i ++)
	{
		for(int j = 0; j < M; j ++)
			scanf("%d", &input_map[i][j]);
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j ++)
		{
			if(input_map[i][j] == 0)
				made_first_wall(i, j);
		}
	}
	printf("%d\n", max);
}