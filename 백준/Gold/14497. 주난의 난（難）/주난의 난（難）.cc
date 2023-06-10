#include <iostream>
#include <queue>

using namespace std;

int H, W;

int dest_y, dest_x, start_y, start_x;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
char mp[300][301];
int answer;

int visited[300][300];
queue<pair<int, int> >que;

void dfs(int y, int x, int time)
{
	if(visited[y][x])
		return;
	visited[y][x] = time;
	for(int i = 0; i < 4; i ++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= H || nx < 0 || nx >= W)
			continue;
		if(visited[ny][nx])
			continue;
		//cout << "que.push " << ny << " " << nx << endl;
		if(mp[ny][nx] == '1' || mp[ny][nx] == '#')
		{
			visited[ny][nx] = time;
			que.push({ny, nx});
		}
		else
			dfs(ny, nx, time);
	}
}

void bfs()
{
	visited[start_y][start_x] = 1;
	que.push({start_y, start_x});
	while(!que.empty())
	{
		int y = que.front().first;
		int x = que.front().second;
		// cout << y << " " << x << endl;
		que.pop();
		if(y == dest_y && x == dest_x)
		{
			answer = visited[y][x] -1;
			return ;
		}
		for(int i = 0; i < 4; i ++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= H || nx < 0 || nx >= W)
				continue;
			if(visited[ny][nx])
				continue;
			// cout << ny << " " << nx << endl;
			if(mp[ny][nx] == '1' || mp[ny][nx] == '#')
			{
				visited[ny][nx] = visited[y][x] + 1;
				// cout << "que.push " << ny << " " << nx << endl;
				que.push({ny, nx});
			}
			else if(mp[ny][nx] == '0')
			{
				dfs(ny, nx, visited[y][x] + 1);
			}
		}
	}
}

int main()
{
	cin >> H >> W;
	cin >> start_y >> start_x >> dest_y >> dest_x;
	for(int j = 0; j < H; j ++)
		cin >> mp[j];
	dest_y --;
	dest_x --;
	start_y --;
	start_x --;
	bfs();
	cout << answer << endl;
}