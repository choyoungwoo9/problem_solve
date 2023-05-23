#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, X;
vector<pair<int, int> >node[1001];

int dist[1001][1001];

int INF = 1000000000;

void djikstra(int start)
{
	for(int i = 1; i <= N; i ++)
		dist[start][i] = INF;
	dist[start][start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >que;
	que.push(pair<int, int>(0, start));
	for(int i = 0; i < node[start].size(); i ++)
	{
		que.push(pair<int, int>(node[start][i].second, node[start][i].first));
	}
	while(!que.empty())
	{
		int index = que.top().second;
		int cost = que.top().first;
		que.pop();
		if(dist[start][index] == INF)
		{
			for(int i = 0; i < node[index].size(); i ++)
			{
				if(dist[start][node[index][i].first] > node[index][i].second + cost)
					que.push(pair<int, int>(node[index][i].second + cost, node[index][i].first));
			}
		}
		if(dist[start][index] > cost)
			dist[start][index] = cost;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> X;
	for(int i = 0; i < M; i ++)
	{
		int v1, v2, c;
		cin >> v1 >> v2 >> c;
		node[v1].push_back(pair<int, int>(v2, c));
	}
	for(int i = 1; i <= N; i ++)
	{
		djikstra(i);
	}
	int answer = 0;
	for(int i = 1; i <= N; i ++)
	{
		if(i == X)
			continue;
		if(dist[X][i] + dist[i][X] > answer)
		{
			answer = dist[X][i] + dist[i][X];
		}
	}

	cout << answer << endl;
}