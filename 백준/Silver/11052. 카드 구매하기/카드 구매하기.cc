#include <iostream>

using namespace std;

int N;

int ar[1001];

int dp[1001];

int main()
{
	cin >> N;
	for(int i = 1; i <= N; i ++)
		cin >> ar[i];
	for(int i = 1; i <= N; i ++)
	{
		dp[i] = ar[i];
		for(int j = 1; j <= i - 1; j ++)
		{
			if(dp[j] + dp[i-j] > dp[i])
			{
				dp[i] = dp[j] + dp[i-j];
			}
		}
	}
	cout << dp[N] << endl;
}