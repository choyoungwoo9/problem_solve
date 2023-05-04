#include <iostream>
#include <queue>
using namespace std;

int N;

int my_map[20][20];
int tmp_map[20][20];
int s_i;
int s_j;
int s_size = 2;

int level_store;

int answer;
int flag;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};



void bfs()
{
	queue<pair <int, pair<int, int> > > que;

	que.push(make_pair(s_i, make_pair(s_j, answer)));
	tmp_map[s_i][s_j] = -1;
	while(1)
	{
		if(que.empty())
		{
			flag = 1;
			return ;
		}
		int t_i, t_j, t_time;
		t_i = que.front().first;
		t_j = que.front().second.first;
		t_time = que.front().second.second;
		// cout << t_i << " " << t_j << " " << t_time << endl;
		// cout << my_map[t_i][t_j] << endl;
		que.pop();
		if(my_map[t_i][t_j] > 0 && my_map[t_i][t_j] < s_size)
		{
			while(1)
			{
				if(que.empty())
					break;
				if(que.front().second.second > t_time)
					break;
				if(my_map[que.front().first][que.front().second.first] >= s_size || my_map[que.front().first][que.front().second.first] == 0)
				{
					que.pop();
					continue;
				}
				if(que.front().first < t_i)
				{
					t_i = que.front().first;
					t_j = que.front().second.first;
				}
				else if(que.front().first == t_i && que.front().second.first < t_j)
				{
					t_i = que.front().first;
					t_j = que.front().second.first;
				}
				que.pop();
			}
			//cout << "catch !! " << endl;
			my_map[t_i][t_j] = 0;
			answer = t_time;
			level_store ++;
			if(level_store == s_size)
			{
				level_store = 0;
				s_size ++;
			}
			s_i = t_i;
			s_j = t_j;
			return ;
		}
		for(int i = 0; i < 4; i ++)
		{
			if(t_i + dx[i] < 0 || t_i + dx[i] >= N)
				continue;
			if(t_j + dy[i] < 0 || t_j + dy[i] >= N)
				continue;
			if(tmp_map[t_i+dx[i]][t_j+dy[i]] == -1)
				continue;
			if(my_map[t_i+dx[i]][t_j+dy[i]] > s_size)
			{
				//cout << t_i+dy[i] << " " << t_j+dx[i] << "here\n";
				continue;
			}
			tmp_map[t_i+dx[i]][t_j+dy[i]] = -1;
			que.push(make_pair(t_i+dx[i], make_pair(t_j+dy[i], t_time+1)));
		}
	}
}

void solution()
{
	while(1)
	{
		bfs();
		if(flag)
			break;
		for(int i = 0; i < N; i ++)
		{
			for(int j = 0; j < N; j ++)
			{
				tmp_map[i][j] = 0;
			}
		}
	}
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		for(int j = 0; j < N; j ++)
		{
			int num;
			cin >> num;
			if(num == 9)
			{
				s_i = i;
				s_j = j;
			}
			else
			{
				my_map[i][j] = num;
			}
		}
	}
	solution();
	cout << answer << endl;
}