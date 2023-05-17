#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int ar[401][401];
vector<pair<int, int> >node[401];
int INF = 100000000;

int V;

void dijkstra(int start)
{
	for(int i = 0; i < V; i ++)
	{
		ar[start][i] = INF;
	}
	ar[start][start] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(start, 0));
	while(!pq.empty())
	{
		int current = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();
		if(ar[start][current] < distance)
			continue;
		for(int i = 0; i < node[current].size(); i ++)
		{
			int my_next = node[current][i].first;
			int nextDistance = distance + node[current][i].second;
			if(nextDistance < ar[start][my_next])
			{
				ar[start][my_next] = nextDistance;
				pq.push(make_pair(my_next, -nextDistance));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int E;

	cin >> V >> E;
	for(int i = 0; i < E; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		node[a-1].push_back(pair<int, int>(b-1, c));
	}

	for(int i = 0; i < V; i ++)
		dijkstra(i);

	int answer = -1;
	for(int i = 0; i < V; i ++)
	{
		for(int j = 0; j < V; j ++)
		{
			if(i == j)
				continue;
			if(ar[i][j] == INF || ar[j][i] == INF)
				continue;
			if(answer == -1 || ar[i][j] + ar[j][i] < answer)
				answer = ar[i][j] + ar[j][i];
		}
	}
	cout << answer << endl;
}