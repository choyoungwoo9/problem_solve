#include <iostream>

using namespace std;

int n, k;

int INF = 2100000000;
int dp[10001];

int main()
{
	cin >> n >> k;

	for(int i = 1; i <= 10000; i ++)
		dp[i] = INF;
	for(int i = 0; i < n; i ++)
	{
		int num;
		cin >> num;
		if(num <= 10000)
			dp[num] = 1;
		for(int j = num; j <= 10000; j ++)
		{
			dp[j] = min(dp[j], dp[j-num] + 1);
		}
	}

	if(dp[k] == INF)
		cout << "-1\n";
	else
		cout << dp[k] << endl;
}