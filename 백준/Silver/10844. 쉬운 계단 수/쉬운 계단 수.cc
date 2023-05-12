#include <iostream>

using namespace std;

int N;


int dp[10][101];

void make_dp_table()
{
	for(int i = 1; i <= 9; i ++)
		dp[i][1] = 1;
	for(int i = 2; i <= N; i ++)
	{
		for(int j = 0; j <= 9; j ++)
		{
			if(j == 0)
				dp[0][i] = dp[1][i-1];
			else if(j == 9)
				dp[9][i] = dp[8][i-1];
			else
			{
				dp[j][i] = (dp[j-1][i-1] + dp[j+1][i-1]) % 1000000000;
			}
		}
	}
}

int main()
{
	cin >> N;
	make_dp_table();
	int answer = 0;
	for(int i = 0; i <= 9; i ++)
	{
		answer = (answer + dp[i][N]) % 1000000000;
	}
	cout << answer << endl;
}