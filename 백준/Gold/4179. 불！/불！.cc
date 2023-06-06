#include <iostream>
#include <queue>

using namespace std;

char mp[1000][1001];
int H, W;

int answer;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

queue<pair<pair<int, int>, int> > fq;
queue<pair<pair<int, int>, int> > mq;

void fire()
{
	if(fq.empty())
	{
		return ;
	}
	int start_level = fq.front().second;
	while(!fq.empty())
	{
		if(start_level != fq.front().second)
			break;
		int y = fq.front().first.first;
		int x = fq.front().first.second;
		fq.pop();
		if(start_level != 0 && mp[y][x] == 'F')
			continue;
		mp[y][x] = 'F';
		for(int i = 0; i < 4; i ++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= H || nx < 0 || nx >= W)
				continue;
			if(mp[ny][nx] == 'F' || mp[ny][nx] == '#')
				continue;
			fq.push({{ny, nx}, start_level+1});
		}
	}
	// for(int j = 0; j < H; j ++)
	// {
	// 	for(int i = 0; i < W; i ++)
	// 		cout << mp[j][i];
	// 	cout << '\n';
	// }
}

void bfs(int s_i, int s_j)
{
	mq.push({{s_i, s_j}, 0});
	int cost = 0;
	while(!mq.empty())
	{
		int y = mq.front().first.first;
		int x = mq.front().first.second;
		if(mq.front().second != cost)
			fire();
		cost = mq.front().second;
		mq.pop();
		if(mp[y][x] == 'F')
			continue;
		for(int i = 0; i < 4; i ++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= H || nx < 0 || nx >= W)
			{
				cout << cost + 1 << endl;
				return ;
			}
			if(mp[ny][nx] == '#' || mp[ny][nx] == 'J' || mp[ny][nx] == 'F')
				continue;
			mp[ny][nx] = 'J';
			mq.push({{ny, nx}, cost+1});
		}
	}
	cout << "IMPOSSIBLE" << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> H >> W;
	for(int j = 0; j < H; j ++)
		cin >> mp[j];
	int s_j, s_i;
	for(int j = 0; j < H; j ++)
		for(int i = 0; i < W; i ++)
		{
			if(mp[j][i] == 'F')
				fq.push({{j, i}, 0});
			if(mp[j][i] == 'J')
			{
				s_j = j;
				s_i = i;
			}
		}
	fire();
	bfs(s_j, s_i);
}