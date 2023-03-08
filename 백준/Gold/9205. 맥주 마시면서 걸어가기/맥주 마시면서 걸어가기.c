#include <stdio.h>

typedef struct node
{
	int visited;
	int x;
	int y;
}	node;

node ar[101];
int n;
int s_x, s_y;

int flag;

int abs(int a)
{
	if(a < 0)
		a = a * -1;
	return a;
}

void dfs(int x, int y)
{
	if(x == ar[n].x && y == ar[n].y)
	{
		flag = 1;
		return ;
	}
	for(int i = 0; i <= n; i ++)
	{
		if((abs(ar[i].x - x) + abs(ar[i].y - y)) <= 1000 && ar[i].visited == 0)
		{
			ar[i].visited = 1;
			dfs(ar[i].x, ar[i].y);
		}
	}
}
void solution()
{
	flag = 0;
	scanf("%d", &n);
	scanf("%d %d", &s_x, &s_y);
	for(int i = 0; i <= n; i ++)
	{
		ar[i].visited = 0;
		scanf("%d %d", &ar[i].x, &ar[i].y);
	}
	dfs(s_x, s_y);
	if(flag == 0)
		printf("sad\n");
	else
		printf("happy\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int i = 0;i < T; i ++)
	{
		solution();
	}
}