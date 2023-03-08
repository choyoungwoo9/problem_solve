#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

void get_answer(int *ar, int left, int right, int num)
{
	//sleep(1);
	//printf("answer : left %d right %d num %d\n", left, right, num);
	if(*(ar + (right + left) / 2) == num)
	{
		printf("1\n");
		return ;
	}
	if(right <= left)
	{
		printf("0\n");
		return ;
	}
	if(*(ar + (left + right) / 2) > num)
	{
		get_answer(ar, left, (right + left)/2 - 1, num);
	}
	if(*(ar + (left + right) / 2) < num)
	{
		get_answer(ar, (right + left)/2 + 1, right, num);
	}
}

int main()
{
	int N;
	int *N_ar;
	int M;
	int *M_ar;
	scanf("%d", &N);
	N_ar = malloc(sizeof(int) * N);
	for(int i = 0; i < N; i ++)
	{
		scanf("%d", (N_ar + i));
	}
	scanf("%d", &M);
	M_ar = malloc(sizeof(int) * M);
	for(int i = 0; i < M; i ++)
	{
		scanf("%d", (M_ar + i));
	}

	qsort(N_ar, N, sizeof(int), compare);
	for(int i = 0; i < M; i ++)
	{
		get_answer(N_ar, 0, N - 1, *(M_ar + i));
	}
}