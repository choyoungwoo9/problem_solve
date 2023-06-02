#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
using namespace std;

int N, M;

int mp[8][8];

int tmp[3];

int answer = 0;

int tmp_mp[8][8];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int y, int x)
{
	tmp_mp[y][x] = 2;
	for(int i = 0; i < 4; i ++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;
		if(tmp_mp[ny][nx] == 0)
			dfs(ny, nx);
	}
}

void solve()
{
	vector<pair<int, int> > vt;
	for(int j = 0; j < N; j ++)
	{
		for(int i = 0; i < M; i ++)
		{
			tmp_mp[j][i] = mp[j][i];
			if(tmp_mp[j][i] == 2)
			{
				vt.push_back(pair<int, int>(j, i));
			}
		}
	}
	for(auto it : vt)
	{
		dfs(it.first, it.second);
	}
	int cnt = 0;
	for(int j = 0; j < N; j ++)
	{
		for(int i = 0; i < M; i ++)
		{
			if(tmp_mp[j][i] == 0)
				cnt ++;
		}
	}
	if(cnt > answer)
		answer = cnt;
}

void combi(int num, int cnt)
{
	if(cnt == 3)
	{
		for(int i = 0; i < 3; i ++)
		{
			int y = tmp[i] / M;
			int x = tmp[i] % M;
			if(mp[y][x] != 0)
				return;
		}
		
		for(int i = 0; i < 3; i ++)
		{
			int y = tmp[i] / M;
			int x = tmp[i] % M;
			mp[y][x] = 1;
		}

		solve();
		for(int i = 0; i < 3; i ++)
		{
			int y = tmp[i] / M;
			int x = tmp[i] % M;
			mp[y][x] = 0;
		}
		return ;
	}

	for(int i = num + 1; i < N*M; i ++)
	{
		tmp[cnt] = i;
		combi(i, cnt + 1);
	}
}

int main()
{
	cin >> N >> M;
	for(int j = 0; j < N; j ++)
		for(int i = 0; i < M; i ++)
			cin >> mp[j][i];
	combi(-1, 0);
	cout << answer << endl;
}