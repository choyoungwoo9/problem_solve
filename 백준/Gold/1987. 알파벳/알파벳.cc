#include <iostream>

using namespace std;

int H, W;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int visited[20][20];
char mp[20][21];
int ar[26];

int ans = 0;

void dfs(int y, int x, int depth)
{
	for(int i = 0; i < 4; i ++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= H || nx < 0 || nx >= W || visited[ny][nx])
			continue;
		if(ar[mp[ny][nx]-'A'])
			continue;
		ar[mp[ny][nx]-'A'] = 1;
		visited[ny][nx] = 1;
		dfs(ny, nx, depth+1);
		ar[mp[ny][nx]-'A'] = 0;
		visited[ny][nx] = 0;
	}
	ans = max(ans, depth);
}

int main()
{
	cin >> H >> W;
	for(int j = 0; j < H; j ++)
		cin >> mp[j];
	visited[0][0] = 1;
	ar[mp[0][0]-'A'] = 1;
	dfs(0, 0, 1);
	cout << ans << endl;
}