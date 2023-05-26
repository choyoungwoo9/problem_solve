#include <iostream>
#include <algorithm>
using namespace std;

int M, N, K;

int m_map[101][101];

int ar[10000];
int answer = 0;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int y, int x)
{
	if(m_map[y][x])
		return ;
	
	ar[answer] ++;
	m_map[y][x] = 1;

	for(int k = 0; k < 4; k ++)
	{
		if(dy[k] + y < 0 || dy[k] + y >= M)
			continue;
		if(dx[k] + x < 0 || dx[k] + x >= N)
			continue;
		dfs(y + dy[k], x + dx[k]);
	}
}

int main()
{
	cin >> M >> N >> K;
	for(int i = 0; i < K; i ++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for(int i = x1; i < x2; i ++)
		{
			for(int j = y1; j < y2; j++)
				m_map[j][i] = 1;
		}
	}

	// for(int i = 0; i < M; i ++)
	// {
	// 	for(int j = 0; j < N; j++)
	// 		cout << m_map[i][j] << " ";
	// 	cout << endl;
	// }
	for(int y = 0; y < M; y ++)
	{
		for(int x = 0; x < N; x++)
		{
			if(m_map[y][x])
				continue;
			dfs(y, x);
			answer ++;
		}
	}
	sort(ar, ar+answer);
	cout << answer << "\n";
	for(int i = 0; i < answer; i ++)
		cout << ar[i] << " ";
	cout << "\n";
}