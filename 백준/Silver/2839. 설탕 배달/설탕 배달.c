#include <stdio.h>
#include <stdlib.h>

int N;

int main()
{
	scanf("%d", &N);
	for(int i = 0; 3 * i <= N; i ++)
	{
		if((N - 3 * i) % 5  == 0)
		{
			printf("%d\n", i + (N - 3 * i) / 5);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}