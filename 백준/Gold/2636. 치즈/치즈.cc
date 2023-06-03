#include <iostream>

using namespace std;

int mp[100][100];

int H, W;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int visited[100][100];
int dfs(int y, int x)
{
	visited[y][x] = 1;
	if(mp[y][x] == 1)
	{
		mp[y][x] = -1;
		return 1;
	}
	int ret = 0;
	for(int i = 0; i < 4; i ++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= H || nx < 0 || nx >= W)
			continue;
		if(mp[ny][nx] == -1 || visited[ny][nx])
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

	int time_ans = 0;
	int cnt_ans = 0;
	while(1)
	{
		int cnt = dfs(0, 0);
		if(cnt == 0)
			break;
		for(int j = 0; j < H; j ++)
			for(int i = 0; i < W; i ++)
			{
				if(mp[j][i] == -1)
					mp[j][i] = 0;
				visited[j][i] = 0;
			}
		cnt_ans = cnt;
		time_ans ++;
	}
	cout << time_ans << "\n" << cnt_ans << "\n";
}
