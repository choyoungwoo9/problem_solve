#include <stdio.h>
#include <stdlib.h>

char map[25][26];

int N;

int count;
int count_ar[25 * 25];

int compare(const void *a, const void *b)
{
	return (*(int *)a) - (*(int *)b);
}

void dfs(int i, int j)
{
	if(i < 0 || i >= N || j < 0 || j >= N || map[i][j] == '2' ||map[i][j] == '0')
		return;
	count_ar[count] ++;
	map[i][j] = '2';
	int dx[4] = {-1, 0, 0, 1};
	int dy[4] = {0, 1, -1, 0};
	for(int k = 0; k < 4; k ++)
	{
		dfs(i + dx[k], j + dy[k]);
	}
}

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i ++)
	{
		scanf("%s", map[i]);
	}
	count = 0;
	for(int i = 0; i < N; i ++)
	{
		for(int j = 0; j < N; j ++)
		{
			if(map[i][j] == '1')
			{
				count ++;
				dfs(i, j);
			}
		}
	}
	printf("%d\n", count);
	qsort(count_ar+1, count, sizeof(int), compare);
	for(int i = 1; i <= count; i ++)
	{
		printf("%d\n", count_ar[i]);
	}
}