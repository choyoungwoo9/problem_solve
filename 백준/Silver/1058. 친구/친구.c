#include<stdio.h>

int N;
char map[50][51];
int tmp[50];
int max = 0;

void get_double_friend(int my_row)
{
	for(int i = 0; i < N; i ++)
		tmp[i] = 0;
	for(int i = 0; i < N; i ++)
	{
		if(map[my_row][i] == 'Y')
		{
			tmp[i] = 1;
			for(int j = 0; j < N; j ++)
			{
				if(my_row == j)
					continue;
				if(map[i][j] == 'Y')
					tmp[j] = 1;
			}
		}
	}
	int friend_count = 0;
	for(int i = 0; i < N; i ++)
	{
		if(tmp[i] == 1)
			friend_count ++;
	}
	//printf("row : %d, tmp : %d\n", my_row, friend_count);
	if(friend_count > max)
		max = friend_count;
}

void solution()
{
	for(int i = 0; i < N; i ++)
	{
		get_double_friend(i);
	}
	printf("%d\n", max);
}

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i ++)
		scanf(" %s", map[i]);
	solution();
}