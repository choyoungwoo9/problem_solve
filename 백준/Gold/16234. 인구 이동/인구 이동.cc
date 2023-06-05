#include <iostream>
#include <vector>

using namespace std;

int N, L, R;

int mp[50][50];
int visited[50][50];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs(int y, int x, vector<pair<int, int> >&vt)
{
	vt.push_back(pair<int, int>(y, x));
	visited[y][x] = 1;
	int ret = mp[y][x];
	for(int i = 0; i < 4; i ++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= N || nx < 0 || nx >= N)
			continue;
		if(visited[ny][nx])
			continue;
		int gap = abs(mp[y][x] - mp[ny][nx]);
		if(gap <= R && gap >= L)
		{
			ret += dfs(ny, nx, vt);
		}
	}
	return ret;
}

int main()
{
	cin >> N >> L >> R;
	for(int j = 0; j < N; j ++)
		for(int i = 0; i < N; i ++)
			cin >> mp[j][i];

	int answer = 0;
	while(1)
	{
		int flag = 1;
		for(int j = 0; j < N; j ++)
			for(int i = 0; i < N; i ++)
				visited[j][i] = 0;
		for(int j = 0; j < N; j ++)
		{
			for(int i = 0; i < N; i ++)
			{
				if(visited[j][i] == 0)
				{
					vector<pair<int, int> > vt;
					int sum = dfs(j, i, vt);
					for(auto idx : vt)
					{
						mp[idx.first][idx.second] = sum / vt.size();
					}
				}
				else
					flag = 0;
			}
		}
		if(flag)
			break;
		answer ++;
	}
	cout << answer << endl;
}