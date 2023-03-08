#include <iostream>
#include <queue>
#include <utility>
using namespace std;

//M -> R, N -> C
int M, N;
int map[1000][1000];
int tomato_count;
int day;

pair <int, pair<int, int> >p;
queue<pair<int, pair<int, int> > > que;

void bfs()
{
	while(1)
	{
		if(que.empty())
			break ;
		int cur_day = que.front().first;
		if(cur_day != day)
			break ;
		int cur_i = que.front().second.first;
		int cur_j = que.front().second.second;
		que.pop();
		if(map[cur_i][cur_j] == 1 && day != 0)
			continue;
		if(day != 0)
			map[cur_i][cur_j] = 1;
		if(day != 0)
			tomato_count --;
		//cout << "index :: "<< cur_i << ' ' << cur_j << endl;
		int dx[4] = {-1, 0, 0, 1};
		int dy[4] = {0, 1, -1, 0};
		for(int k = 0; k < 4; k ++)
		{
			if(cur_i+dx[k] < 0 || cur_i+dx[k] >= M || cur_j+dy[k] < 0 || cur_j+dy[k] >= N)
			{
				//cout << cur_i+dx[k] << ' ' << cur_j+dy[k] << endl;
				continue;
			}
			//printf("dd\n");
			if(map[cur_i+dx[k]][cur_j+dy[k]] == 0)
				que.push(make_pair(day+1, make_pair(cur_i+dx[k], cur_j+dy[k])));
		}
	}
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i < M; i ++)
	{
		for(int j = 0; j < N; j ++)
		{
			cin >> map[i][j];
			if(map[i][j] == 1)
			{
				que.push(make_pair(0, make_pair(i, j)));
			}
			else if(map[i][j] == 0)
				tomato_count ++;
		}
	}
	while(1)
	{
		int today_count = tomato_count;
		bfs();
		if(tomato_count == 0)
		{
			cout << day << endl;
			break ;
		}
		if(today_count == tomato_count && day != 0)
		{
			cout << -1 << endl;
			break ;
		}
		day ++;
	}
	// for(int i = 0; i < M; i ++)
	// {
	// 	for(int j = 0; j < N; j ++)
	// 	{
	// 		cout << map[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
}