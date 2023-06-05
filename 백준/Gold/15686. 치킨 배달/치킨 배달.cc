#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, M;
vector<pair<int, int> > chicken_ar;
vector<pair<int, int> > home_ar;
int mp[50][50];
int answer = -1;

// int dx[4] = {0, 0, 1, -1};
// int dy[4] = {1, -1, 0, 0};

// int visited[50][50];
// int bfs(int y, int x)
// {
// 	for(int j = 0; j < N; j ++)
// 		for(int i = 0; i < N; i ++)
// 			visited[j][i] = 0;
// 	queue<pair<pair<int, int>, int> > que;
// 	que.push(pair<pair<int, int>, int>(pair<int, int>(y, x), 0));
// 	while(!que.empty())
// 	{
// 		int cur_y = que.front().first.first;
// 		int cur_x = que.front().first.second;
// 		int cur_score = que.front().second;
// 		que.pop();
// 		if(mp[cur_y][cur_x] == 2)
// 			return cur_score;
// 		for(int i = 0; i < 4; i ++)
// 		{
// 			int ny = cur_y + dy[i];
// 			int nx = cur_x + dx[i];
// 			if(ny < 0 || ny >= N || nx < 0 || ny >= N)
// 				continue;
// 			if(visited[ny][nx])
// 				continue;
// 			visited[ny][nx] = 1;
// 			que.push(pair<pair<int, int>, int>(pair<int, int>(ny, nx), cur_score+1));
// 		}
// 	}
// 	return -10000;
// }

void solve(vector<pair<int, int> >&vt)
{
	int cur = 0;
	for(auto p : home_ar)
	{
		int h_j = p.first;
		int h_i = p.second;
		int tmp = 10000;
		for(auto c : vt)
		{
			int c_j = c.first;
			int c_i = c.second;
			tmp = min(tmp, abs(c_j - h_j) + abs(c_i - h_i));
		}
		cur += tmp;
	}
	if(answer < 0)
		answer = cur;
	answer = min(cur, answer);
}

void combi(int idx, vector<pair<int, int> > &vt)
{
	if(vt.size() == M)
	{
		solve(vt);
		return ;
	}

	for(int i = idx+1; i < chicken_ar.size(); i ++)
	{
		vt.push_back(pair<int, int>(chicken_ar[i].first, chicken_ar[i].second));
		// mp[chicken_ar[i].first][chicken_ar[i].second] = 2;

		combi(i, vt);

		// mp[chicken_ar[i].first][chicken_ar[i].second] = 0;
		vt.pop_back();
	}
}

int main()
{
	cin >> N >> M;
	for(int j = 0; j < N; j ++)
	{
		for(int i = 0; i < N; i ++)
		{
			int num;
			cin >> num;
			if(num == 1)
				home_ar.push_back(make_pair(j, i));
			if(num == 2)
				chicken_ar.push_back(make_pair(j, i));
		}
	}
	vector<pair<int, int> > vt;
	combi(-1, vt);
	cout << answer << endl;
}