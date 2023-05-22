#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int INF = 2000000000;

int N, M, A, B;
vector<pair<int, int> > vertex[1001];

int dist[1001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;

void dijkstra()
{
	dist[A] = 0;
	for(auto it = vertex[A].begin(); it != vertex[A].end(); it++)
	{
		pq.push(pair<int, int>(it->first, it->second));
	}
	while(!pq.empty())
	{
		int index = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if(dist[index] < cost)
			continue;
		if(dist[index] == INF)
		{
			for(auto it = vertex[index].begin(); it != vertex[index].end(); it++)
			{
				if(it->first + cost > dist[it->second])
					continue;
				pq.push(pair<int, int>(it->first + cost, it->second));
			}
		}
		dist[index] = cost;
	}
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i < M; i ++)
	{
		int n1, n2, c;
		cin >> n1 >> n2 >> c;
		vertex[n1].push_back(pair<int, int>(c, n2));
	}
	for(int i = 1; i <= N; i ++)
		dist[i] = INF;
	cin >> A >> B;
	dijkstra();
	cout << dist[B] << endl;
}