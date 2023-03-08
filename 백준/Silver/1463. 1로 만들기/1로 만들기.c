	#include <stdio.h>

	int N;
	int count;

	//100이면은
	//99의 최적과 50의 최적을 비교하면 됨

	//1부터 N까지 최적을 만들어 나가자
	//나누기를 해 몫에 따라서 최적을 만들자

	int dp_ar[1000001];

	int min(int a, int b)
	{
		if(a > b)
			return b;
		return a;
	}

	void solution()
	{
		int tmp = 1;
		while(tmp <= N)
		{
			if(tmp == 1)
			{
				dp_ar[tmp] = 0;
				tmp ++;
				continue ;
			}
			if(tmp % 6 == 0)
			{
				dp_ar[tmp] = min(dp_ar[tmp - 1], min(dp_ar[tmp / 2], dp_ar[tmp / 3]) + 1);
			}
			else if(tmp % 3 == 0)
				dp_ar[tmp] = min(dp_ar[tmp - 1], dp_ar[tmp / 3]) + 1;
			else if(tmp % 2 == 0)
				dp_ar[tmp] = min(dp_ar[tmp - 1], dp_ar[tmp / 2]) + 1;
			else
				dp_ar[tmp] = dp_ar[tmp - 1] + 1;
			tmp ++;
		}
		printf("%d", dp_ar[N]);
	}

	int main()
	{
		scanf("%d", &N);
		solution();
	}