#include <iostream>

using namespace std;

int N, M;

int mp[50][50];

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void dfs(int y, int x)
{
	if(mp[y][x] == 0)
		return ;
	mp[y][x] = 0;
	for(int i = 0; i < 4; i ++)
	{
		if(y+dy[i] < 0 || y+dy[i] >= N)
			continue;
		if(x+dx[i] < 0 || x+dx[i] >= M)
			continue;
		if(mp[y+dy[i]][x+dx[i]] == 0)
			continue;
		dfs(y+dy[i], x+dx[i]);
	}
}

void solve()
{
	int K;
	cin >> M >> N >> K;
	for(int i = 0; i < K; i ++)
	{
		int X, Y;
		cin >> X >> Y;
		mp[Y][X] = 1;
	}
	int answer = 0;
	for(int j = 0; j < N; j ++)
	{
		for(int i = 0; i < M; i ++)
		{
			if(mp[j][i] == 1)
			{
				answer ++;
				dfs(j, i);
			}
		}
	}
	cout << answer << "\n";
}

int main()
{
	int T;
	cin >> T;
	for(int i = 0; i < T; i ++)
	{
		solve();
	}
}