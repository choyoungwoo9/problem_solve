#include <iostream>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int H, W, K;
int answer = 0;
char mp[5][6];
int visited[5][5];
void dfs(int y, int x, int depth)
{
	if(y == 0 && x == W-1)
	{
		if(depth == K)
			answer ++;
		return ;
	}
	for(int i = 0; i < 4; i ++)
	{
		int ny = y+dy[i];
		int nx = x+dx[i];
		if(ny < 0 || ny >= H || nx < 0 || nx >= W || visited[ny][nx] || mp[ny][nx] == 'T')
			continue;
		visited[ny][nx] = 1;
		dfs(ny, nx, depth+1);
		visited[ny][nx] = 0;
	}
}

int main()
{
	cin >> H >> W >> K;
	for(int i = 0; i < H; i ++)
		cin >> mp[i];
	visited[H-1][0] = 1;
	dfs(H-1, 0, 1);
	cout << answer << endl;
}