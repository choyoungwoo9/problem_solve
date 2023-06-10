#include <iostream>
#include <queue>
using namespace std;

int visited[200000];
int before_coming[200000];
int answer;

int p_ar[100001];

int N, K;

void bfs()
{
	queue<pair<int, int> > que;
	que.push({N, 0});
	visited[N] = 1;
	while(!que.empty())
	{
		int idx = que.front().first;
		int time = que.front().second;
		que.pop();

		if(idx == K)
		{
			answer = time;
			break;
		}
		if(idx-1 >= 0 && idx-1 < 200000 && !visited[idx-1])
		{
			visited[idx-1] = 1;
			before_coming[idx-1] = idx;
			que.push({idx-1, time+1});
		}
		if(idx+1 >= 0 && idx+1 < 200000 && !visited[idx+1])
		{
			visited[idx+1] = 1;
			before_coming[idx+1] = idx;
			que.push({idx+1, time+1});
		}
		if(idx*2 >= 0 && idx*2 < 200000 && !visited[idx*2])
		{
			visited[idx*2] = 1;
			before_coming[idx*2] = idx;
			que.push({idx*2, time+1});
		}
	}
}

int main()
{
	cin >> N >> K;
	bfs();
	cout << answer << endl;
	for(int i = answer; i >= 0; i --)
	{
		if(i == answer)
			p_ar[i] = K;
		else
			p_ar[i] = before_coming[p_ar[i+1]];
	}

	for(int i = 0; i <= answer; i ++)
	{
		cout << p_ar[i] << " ";
	}
	cout << endl;
}