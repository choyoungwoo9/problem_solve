#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int INF = 2100000000;
int n, m;

vector<pair<int, int> > vertex[101];
int dist[101];

void djikstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
	dist[start] = 0;
	for(int i = 0; i < vertex[start].size(); i ++)
		pq.push(pair<int, int>(vertex[start][i].first, vertex[start][i].second));
	while(!pq.empty())
	{
		int index = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if(dist[index] < cost)
			continue;
		if(dist[index] == INF)
		{
			for(int i = 0; i < vertex[index].size(); i ++)
			{
				if(cost + vertex[index][i].first > dist[vertex[index][i].second])
					continue;
				pq.push(pair<int, int>(cost + vertex[index][i].first, vertex[index][i].second));
			}
		}
		dist[index] = cost;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>> n >> m;
	for(int i = 0; i < m; i ++)
	{
		int v1, v2, c;
		cin >> v1 >> v2 >> c;
		vertex[v1].push_back(pair<int, int>(c, v2));
	}

	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j<= n; j++)
			dist[j] = INF;
		djikstra(i);
		for(int j = 1; j<= n; j++)
		{
			if(dist[j] == INF)
				cout << "0 ";
			else
				cout << dist[j] << " ";
		}
		cout << "\n";
	}
}
