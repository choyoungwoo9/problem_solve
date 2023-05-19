#include <iostream>

using namespace std;

int n, k;

int dp[10001];

int main()
{
	cin >> n >> k;

	for(int i = 0; i < n; i ++)
	{
		int num;
		cin >> num;
		if(num <= 10000)
			dp[num] = 1;
	}

	for(int i = 2; i <= 10000; i ++)
	{
		for(int j = 1; j < i; j++)
		{
			if(!dp[j] || !dp[i-j])
				continue;
			if(dp[i] == 0 || dp[j] + dp[i-j] < dp[i])
				dp[i] = dp[j] + dp[i-j];
		}
	}
	if(dp[k] == 0)
		cout << "-1\n";
	else
		cout << dp[k] << endl;
}