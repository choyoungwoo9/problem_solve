#include <iostream>
#include <queue>

using namespace std;

int N, M;

char map[100][101];
int visited[100][100];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

queue <pair <int, pair<int, int> > > que;

void bfs()
{
	visited[0][0] = 1;
	for(int i = 0; i < 4; i ++)
	{
		if(0+dx[i] < 0 || 0+dx[i] >= N ||0+dy[i] < 0 || 0+dy[i] >= M)
			continue;
		if(map[0+dx[i]][0+dy[i]] == '1')
		{
			que.push(make_pair(2, make_pair(0+dx[i], 0+dy[i])));
		}
	}
	while(1)
	{
		int day = que.front().first;
		int cur_i = que.front().second.first;
		int cur_j = que.front().second.second;
		que.pop();
		if(visited[cur_i][cur_j])
			continue;
		visited[cur_i][cur_j] = 1;
		if(cur_i == N-1 && cur_j == M-1)
		{
			cout << day << endl;
			return ;
		}
		for(int i = 0; i < 4; i ++)
		{
			if(cur_i+dx[i] < 0 || cur_i+dx[i] >= N ||cur_j+dy[i] < 0 || cur_j+dy[i] >= M)
				continue;
			if(map[cur_i+dx[i]][cur_j+dy[i]] == '1' && !visited[cur_i+dx[i]][cur_j+dy[i]])
				que.push(make_pair(day + 1, make_pair(cur_i+dx[i], cur_j+dy[i])));
		}
	}
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i < N; i ++)
		cin >> map[i];
	bfs();
}