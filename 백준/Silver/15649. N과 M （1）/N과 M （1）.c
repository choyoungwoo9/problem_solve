#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_dup_num(int num, int depth, int *ar)
{
	for(int i = 0; i < depth - 1; i ++)
	{
		if(*(ar + i) == num)
			return 1;
	}
	return 0;
}


void print_ar(int *ar, int depth)
{
	for(int i = 0; i < depth; i ++)
	{
		if(i == depth -1)
			printf("%d\n", *(ar + i));
		else
			printf("%d ", *(ar + i));
	}
}

void dfs(int num, int depth, int current_num, int current_depth, int *ar)
{
	//printf("depth : %d  num: %d\n", current_depth, current_num);
	if(depth < current_depth)
		return ;

	if(check_dup_num(current_num, current_depth, ar))
		return ;
	ar[current_depth - 1] = current_num;
	if(current_depth == depth)
	{
		print_ar(ar, depth);
		return ;
	}
	for(int i = 1; i <= num; i ++)
	{
		dfs(num, depth, i, current_depth + 1, ar);
	}	
}

void my_algo(int N, int M)
{
	int num;
	int depth;
	//int ar[10];

	num = N;
	depth = M;
	//printf("N : %d  M: %d\n", N, M);
	for(int i = 1; i <= num; i ++)
	{
		int *ar = malloc(sizeof(int) * 10);
		dfs(num, depth, i, 1, ar);
	}	
}
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	//printf("%d %d\n", N, M);
	my_algo(N, M);
}

