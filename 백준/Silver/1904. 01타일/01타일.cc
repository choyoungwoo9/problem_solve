#include <iostream>

using namespace std;

int dp[1000001];

int N;

void make_dp()
{
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3; i <= N; i ++)
	{
		dp[i] = (dp[i-1] + dp[i-2]) % 15746;
	}
}

int main()
{
	cin >> N;
	make_dp();
	cout << dp[N] << endl;
}