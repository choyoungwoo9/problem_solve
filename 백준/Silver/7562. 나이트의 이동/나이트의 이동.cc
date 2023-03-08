#include <queue>
#include <iostream>

using namespace std;

int map[300][300];
int N;
int s_i, s_j, d_i, d_j;
int answer_count;

void bfs()
{
	queue<pair< int, pair<int, int> > >que;
	int move_count;
	int i = s_i;
	int j = s_j;
	que.push(make_pair(0, make_pair(i, j)));
	while(1)
	{
		move_count = que.front().first;
		i = que.front().second.first;
		j = que.front().second.second;
		que.pop();
		if(map[i][j] == 1)
			continue;
		map[i][j] = 1;
		if(i == d_i && j == d_j)
		{
			answer_count = move_count;
			return ;
		}
		int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
		int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
		for(int k = 0; k < 8; k ++)
		{
			if(i + dx[k] >= 0 && i + dx[k] < N && j + dy[k] >= 0 && j + dy[k] < N && map[i+dx[k]][j+dy[k]] == 0)
				que.push(make_pair(move_count+1, make_pair(i+dx[k], j+dy[k])));
		}
	}
}

void solution()
{
	cin >> N;
	cin >> s_i >> s_j;
	cin >> d_i >> d_j;
	for(int i = 0; i < N; i ++)
	{
		for(int j = 0; j < N; j ++)
			map[i][j] = 0;
	}
	answer_count = 0;
	bfs();
	printf("%d\n", answer_count);
}

int main()
{
	int T;
	cin >> T;
	for(int i = 0; i < T; i ++)
	{
		solution();
	}
}