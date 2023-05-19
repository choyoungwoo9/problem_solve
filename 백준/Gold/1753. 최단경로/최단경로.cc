#include <iostream>
#include <vector>
#include <queue>

int INF = 2100000000;
using namespace std;

int V, E;

vector<pair<int, int> > index_node[20001];

int dist[20001];

int start;

void dijkstra()
{
	priority_queue<pair<int, int> >que;
	dist[start] = 0;
	for(int i = 0; i < index_node[start].size(); i ++)
		que.push(pair<int, int>(-1 * index_node[start][i].first, index_node[start][i].second));
	while(!que.empty())
	{
		int tmp_dist = -1 * que.top().first;
		int index = que.top().second;
		que.pop();
		if(dist[index] == INF)
		{
			for(int i = 0; i < index_node[index].size(); i ++)
			{
				if(dist[index_node[index][i].second] > (tmp_dist + index_node[index][i].first))
					que.push(pair<int, int>(-1 * (tmp_dist + index_node[index][i].first), index_node[index][i].second));
			}
		}
		if(tmp_dist < dist[index])
			dist[index] = tmp_dist;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> V >> E;
	for(int i = 1; i <= V; i ++)
	{
		dist[i] = INF;
	}
	cin >> start;
	for(int i = 0; i < E; i ++)
	{
		int n1, n2, cost;
		cin >> n1 >> n2 >> cost;
		index_node[n1].push_back(pair<int, int>(cost, n2));
	}
	dijkstra();
	for(int i = 1; i <= V; i ++)
	{
		if(dist[i] == INF)
			cout << "INF";
		else
			cout << dist[i];
		cout << "\n";
	}
}