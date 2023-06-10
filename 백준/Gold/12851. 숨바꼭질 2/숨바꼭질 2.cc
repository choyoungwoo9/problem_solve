#include <iostream>
#include <queue>
using namespace std;

int visited[160000];
int N, K;
int answer;
int cnt;

int flag = 0;
int before_time = -1;

void bfs()
{
	queue<pair<int, int> >que;
	que.push({N, 1});
	while(!que.empty())
	{
		int cur_idx = que.front().first;
		int cur_time = que.front().second;
		que.pop();
		if(before_time != cur_time && flag)
			return ;
		if(cur_idx == K)
		{
			flag = 1;
			answer = cur_time;
			cnt ++;
		}
		before_time = cur_time;
		if(visited[cur_idx] > cur_time)
			continue;
		visited[cur_idx] = cur_time;
		if(cur_idx - 1 >= 0 && cur_idx - 1 < 160000 && !visited[cur_idx - 1])
			que.push({cur_idx -1, cur_time + 1});
		if(cur_idx + 1 >= 0 && cur_idx + 1 < 160000 && !visited[cur_idx + 1])
			que.push({cur_idx + 1, cur_time + 1});
		if(cur_idx * 2 >= 0 && cur_idx * 2 < 160000 && !visited[cur_idx * 2])
			que.push({cur_idx * 2, cur_time + 1});
	}
}

int main()
{
	cin >> N >> K;
	bfs();
	answer --;
	cout << answer << endl;
	cout << cnt << endl;
}