#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) 
{ 

    return (*(int *)a - *(int *)b);
}

int N, L;
int *leak_point;
double point = 0;
int answer = 0;
void check_already_attach(int i)
{
	if(point < leak_point[i] + 0.5)
	{
		answer ++;
		if(point < leak_point[i] - 0.5)
		{
			point = leak_point[i] - 0.5 + L;
		}
		else
		{
			point = point + L;
		}
	}
	else
	{
		return ;
	}
}

int main()
{
	scanf("%d %d", &N, &L);
	leak_point = malloc(sizeof(int) * N);
	for(int i = 0; i < N; i++)
		scanf(" %d", &leak_point[i]);
	qsort(leak_point, N, sizeof(int), compare);
	// for(int i = 0; i < N; i ++)
	// {
	// 	printf(" %d", leak_point[i]);
	// }
	for(int i = 0; i < N; i ++)
	{
		check_already_attach(i);
		//printf("point : %f\n", point);
	}
	printf("%d", answer);
}