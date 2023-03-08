#include <stdio.h>
#include <stdlib.h>

int count_0;
int count_1;

int recursive_fibonacci(int n)
{
	if(n == 0)
	{
		count_0 ++;
		return 0;
	}
	if(n == 1)
	{
		count_1 ++;
		return 1;
	}
	return (recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2));
}

int fibo_ar[41 * 2];

void dp_fibonacci()
{
	for(int i = 0; i <= 40; i ++)
	{
		if(i == 0)
		{
			fibo_ar[0] = 1;
			fibo_ar[1] = 0;
		}
		else if(i == 1)
		{
			fibo_ar[2] = 0;
			fibo_ar[3] = 1;
		}
		else
		{
			fibo_ar[2 * i] = fibo_ar[2 * i - 2] + fibo_ar[2 * i - 4];
			fibo_ar[2 * i + 1] = fibo_ar[2 * i - 2 + 1] + fibo_ar[2 * i - 4 + 1];
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	dp_fibonacci();
	for(int i = 0; i < T; i ++)
	{
		int n;
		count_0 = 0;
		count_1 = 0;
		scanf(" %d", &n);
		//recursive_fibonacci(n);
		//printf("%d %d\n", count_0, count_1);
		printf("%d %d\n", fibo_ar[n*2], fibo_ar[n*2 + 1]);
	}
}