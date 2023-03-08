#include <stdio.h>

int N, F;

int main()
{
	scanf("%d", &N);
	scanf("%d", &F);
	int answer = 0;
	N = N - (N % 100);
	for(int i = 0; i < 100; i ++)
	{
		if((N + i) % F == 0)
		{
			answer = i;
			break;
		}
	}
	if(answer < 10)
	{
		printf("0");
	}
	printf("%d", answer);
}