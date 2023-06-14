#include <iostream>
#include <queue>
using namespace std;

int N;
int visited[1000];
int mp[1000];

int bfs()
{
	queue<int>que;
	que.push(0);
	visited[0] = 1;
	while(!que.empty())
	{
		int idx = que.front();
		if(idx == N-1)
			return visited[N-1] - 1;
		que.pop();
		for(int i = mp[idx]; i > 0; i --)
		{
			int nidx = idx + i;
			if(nidx >= N)
				continue;
			if(visited[nidx])
				continue;
			que.push(nidx);
			visited[nidx] = visited[idx] + 1;
		}
	}
	return -1;
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i ++)
		cin >> mp[i];
	cout << bfs() << endl;
}