#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int INF = 2100000000;
int n, m;

int map[101][101];

void floyd_warshall()
{
	for(int k = 1; k <= n; k ++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(map[i][k] == INF || map[k][j] == INF)
					continue;
				if(map[i][j] > map[i][k] + map[k][j])
					map[i][j] = map[i][k] + map[k][j];
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(i == j)
				continue;
			map[i][j] = INF;
		}
	}
	for(int i = 0; i < m; i ++)
	{
		int v1, v2, c;
		cin >> v1 >> v2 >> c;
		if(map[v1][v2] > c)
			map[v1][v2] = c;
	}

	floyd_warshall();
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(map[i][j] == INF)
			{
				cout << "0 ";
				continue;
			}
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}
