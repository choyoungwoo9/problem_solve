#include <iostream>

using namespace std;

int N, M;

int dp[31][31];

void make_dp()
{
	for(int i = 1; i <= 30; i ++)
	{
		for(int j = i; j <= 30; j++)
		{
			if(i == j)
			{
				dp[i][j] = 1;
				continue;
			}
			if(i == 1)
				dp[i][j] = j;
			for(int k = j-1; k >= i-1; k --)
			{
				dp[i][j] += dp[i-1][k];
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	make_dp();
	for(int k = 0; k < T; k ++)
	{
		cin >> N >> M;
		cout << dp[N][M] << "\n";
	}
}