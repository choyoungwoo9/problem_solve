#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int a, b;
int N, M;
vector<int> adj[1001];

int visited[1001];

int bfs()
{
	queue<int> que;
	queue<int> cque;
	que.push(a);
	cque.push(0);

	while(!que.empty())
	{
		int num = que.front();
		int cnt = cque.front();
		que.pop();
		cque.pop();
		if(visited[num])
			continue;
		visited[num] = 1;
		if(num == b)
			return cnt;
		for(int i = 0; i < adj[num].size(); i++)
		{
			int nx = adj[num][i];
			if(visited[nx])
				continue;
			que.push(nx);
			cque.push(cnt + 1);
		}
	}
	return -1;
}

int main()
{
	cin >> a >> b;
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cout << bfs() << endl;
}