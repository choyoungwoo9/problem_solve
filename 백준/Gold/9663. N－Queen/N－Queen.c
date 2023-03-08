#include <stdio.h>

int N;
int q_map[15];
int answer;

int abs(int a)
{
	if(a < 0)
		a = a * -1;
	return a;
}

int check_can_locate(int column, int row)
{
	for(int i = 1; i < column; i ++)
	{
		if(q_map[i] == row || abs(q_map[i] - row) == abs(i - column))
			return 0;
	}
	return 1;
}

void locate_queen(int column)
{
	if(column > N)	
		answer ++;
	for(int i = 1; i <= N; i ++)
	{
		if(check_can_locate(column, i))
		{
			q_map[column] = i;
			locate_queen(column+1);
		}
	}
}

int main()
{
	scanf("%d", &N);
	if(N == 0)
	{
		printf("1\n");
		return 0;
	}
	for(int i = 1; i <= N; i ++)
	{
		q_map[1] = i;
		locate_queen(2);
	}
	printf("%d\n", answer);
}