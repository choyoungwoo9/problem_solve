#include <iostream>

using namespace std;

int N, K;

int dp[201][201];

void make_dp_table()
{
	for(int i = 1; i < 201; i ++)
	{
		for(int j = 0; j < 201; j++)
		{
			if(i == 1)
			{
				dp[i][j] = 1;
				continue;
			}
			for(int k = 0; k <= j; k ++)
			{
				dp[i][j] = (dp[i][j] + dp[i-1][k]) % 1000000000;
			}
		}
	}
}

int main()
{
	cin >> N >> K;
	make_dp_table();
	cout << dp[K][N] << endl;
}