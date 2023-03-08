#include <stdio.h>

int W, H;
int map[50][50];
int ggoomtle_map[50][50];

void dfs(int start_i, int start_j)
{
	int stack[2500];
	int stack_count = -1;
	
	stack[++stack_count] = start_i * 50 + start_j;
	while(stack_count >= 0)
	{
		int num = stack[stack_count--];
		int i = num / 50;
		int j = num % 50;
		if(ggoomtle_map[i][j] == 1)
			continue;
		ggoomtle_map[i][j] = 1;
		int dx[4] = {-1, 0, 0, 1};
		int dy[4] = {0, 1, -1, 0};
		for(int k = 0; k < 4; k ++)
		{
			if(i + dy[k] < 0 || i + dy[k] >= H || j + dx[k] < 0 || j + dx[k] >= W)
				continue;
			if(map[i + dy[k]][j + dx[k]] == 1 && ggoomtle_map[i + dy[k]][j + dx[k]] == 0)
				stack[++stack_count] = (i + dy[k]) * 50 + j + dx[k];
		}
	}
}

void solution()
{
	int K;
	scanf("%d %d %d", &W, &H, &K);
	for(int i = 0; i < H; i++)
	{
		for(int j = 0; j < W; j++)
		{
			map[i][j] = 0;
			ggoomtle_map[i][j] = 0;
		}
	}
	for(int i = 0; i < K; i ++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		map[y][x] = 1;
	}
	// for(int i = 0; i < H; i++)
	// {
	// 	for(int j = 0; j < W; j++)
	// 		printf("%d ", map[i][j]);
	// 	printf("\n");
	// }
	int answer = 0;
	for(int i = 0; i < H; i++)
	{
		for(int j = 0; j < W; j++)
		{
			if(map[i][j] == 1 && ggoomtle_map[i][j] == 0)
			{
				dfs(i, j);
				answer ++;
			}
		}
	}
	printf("%d\n", answer);
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int i = 0; i < T; i ++)
	{
		solution();
	}
}