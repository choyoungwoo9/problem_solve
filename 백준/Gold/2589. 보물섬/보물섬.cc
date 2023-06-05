#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
char mp[51][51];

int H, W;
int visited[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs(int y, int x)
{
	for(int j = 0; j < H; j ++)
		for(int i = 0; i < W; i ++)
			visited[j][i] = 0;
	queue<pair<pair<int, int>, int> > que;
	que.push(pair<pair<int, int>, int>(pair<int, int>(y, x), 0));
	visited[y][x] = 1;
	int dist = 0;
	while(!que.empty())
	{
		int cur_y = que.front().first.first;
		int cur_x = que.front().first.second;
		dist = que.front().second;
		//cout << cur_y << " " << cur_x << " " << dist << endl;
		que.pop();
		for(int i = 0; i < 4; i ++)
		{
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];
			if(ny < 0 || ny >= H || nx < 0 || nx >= W)
				continue;
			if(mp[ny][nx] == 'W' || visited[ny][nx])
				continue;
			visited[ny][nx] = 1;
			que.push(pair<pair<int, int>, int>(pair<int, int>(ny, nx), dist+1));
		}
	}
	return dist;
}

int main()
{
	cin >> H >> W;
	for(int j = 0; j < H;j ++)
		cin >> mp[j];
	int answer = 0;
	for(int j = 0; j < H; j ++)
	{
		for(int i = 0; i < W; i ++)
		{
			if(mp[j][i] == 'W')
				continue;
			answer = max(answer, dfs(j, i));
		}
	}
	cout << answer << endl;
}