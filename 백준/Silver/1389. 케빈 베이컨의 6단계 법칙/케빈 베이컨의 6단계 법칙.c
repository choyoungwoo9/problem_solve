#include <stdio.h>

int N, M;
int relation[101][101];

void fill_bacon(int origin, int num, int *count_bacon, int depth)
{
	int tmp[101] = {0};
	int k = 0;
	for(int i = 1; i <= N; i ++)
	{
		if(i == origin || relation[num][i] == 0 || count_bacon[i] != 0)
			continue;
		count_bacon[i] = depth;
		tmp[k] = i;
		k ++;
	}
	for(int i = 0; i < k; i ++)
	{
		fill_bacon(origin, tmp[i], count_bacon, depth + 1);
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; i ++)
	{
		int a, b;
		scanf(" %d %d", &a, &b);
		relation[a][b] = 1;
		relation[b][a] = 1;
	}
	int min = 2147483647;
	int index = 0;
	for(int i = 1; i <= N; i ++)
	{
		int count_bacon[101] = {0, };
		fill_bacon(i, i, count_bacon, 1);
		int bacon = 0;
		for(int j = 1; j <= N; j ++)
		{
			if(i == j)
				continue;
			//printf("j : %d // %d ", j, count_bacon[j]);
			bacon = bacon + count_bacon[j];
		}
		//printf("\ni : %d bacon : %d\n", i, bacon);
		if(bacon < min)
		{
			min = bacon;
			index = i;
		}
	}
	printf("%d\n", index);
}
