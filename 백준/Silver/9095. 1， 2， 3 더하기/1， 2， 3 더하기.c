#include <stdio.h>

int answer, n;

void find_count(int level, int num)
{
	if(num == n)
		answer ++;
	if(level == 0 || num > n)
	{
		return ;
	}
	for(int i = 1; i <= 3; i ++)
	{
		find_count(level - 1, num + i);
	}
}

void solution()
{
	scanf("%d", &n);
	answer = 0;
	find_count(11, 0);
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