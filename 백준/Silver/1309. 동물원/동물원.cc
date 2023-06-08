#include <iostream>

using namespace std;

// int recursive_find(int level, int idx)
// {
// 	if(level == 1)
// 	{
// 		return 1;
// 	}
// 	if(idx == 0)
// 	{
// 		return (recursive_find(level-1, 0) + recursive_find(level-1, 1) + recursive_find(level-1, 2));
// 	}
// 	else if(idx == 1)
// 	{
// 		return (recursive_find(level-1, 0) + recursive_find(level-1, 2));
// 	}
// 	else if(idx == 2)
// 	{
// 		return (recursive_find(level-1, 0) + recursive_find(level-1, 2));
// 	}
// 	return 0;
// }

int dp[100002][3];

void make_dp()
{
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;
	for(int i = 2; i <= 100001; i ++)
	{
		dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % 9901;
		dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % 9901;
		dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % 9901;
	}
}

int main()
{
	int N;
	cin >> N;
	// int answer = recursive_find(N+1, 0);
	make_dp();
	cout << dp[N+1][0] << endl;
}