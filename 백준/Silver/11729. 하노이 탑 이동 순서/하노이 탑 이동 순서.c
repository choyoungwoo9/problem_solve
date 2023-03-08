#include <stdio.h>

int N;
int answer = 0;

void hanoi_check_count(int count, int start, int via, int dest)
{
	if(count == 1)
	{
		answer ++;
		return ;
	}
	hanoi_check_count(count - 1, start, dest, via);
	hanoi_check_count(1, start, via, dest);
	hanoi_check_count(count - 1, via, dest, start);
}

void hanoi(int count, int start, int via, int dest)
{
	if(count == 1)
	{
		printf("%d %d\n", start, dest);
		return ;
	}
	hanoi(count - 1, start, dest, via);
	hanoi(1, start, via, dest);
	hanoi(count - 1, via, start, dest);
}

void solution()
{
	hanoi_check_count(N, 1, 2, 3);
	printf("%d\n", answer);
	hanoi(N, 1, 2, 3);
}

int main()
{
	scanf("%d", &N);
	solution();
}