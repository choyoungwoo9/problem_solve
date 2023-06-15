#include <iostream>

using namespace std;

int H, W;

int mp[500][500];

int cnt = 0;
int mn = 0;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs(int y, int x)
{
	mp[y][x] = 0;
	int ret = 1;
	for(int i = 0; i < 4; i ++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= H || nx < 0 || nx >= W)
			continue;
		if(mp[ny][nx] == 0)
			continue;
		ret += dfs(ny, nx);
	}
	return ret;
}

int main()
{
	cin >> H >> W;
	for(int j = 0; j < H; j ++)
	{
		for(int i = 0; i < W; i ++)
			cin >> mp[j][i];
	}

	for(int j = 0; j < H; j ++)
	{
		for(int i = 0; i < W; i ++)
		{
			if(mp[j][i] == 1)
			{
				cnt ++;
				mn = max(mn, dfs(j, i));
			}
		}
	}
	cout << cnt << endl;
	cout << mn << endl;
}