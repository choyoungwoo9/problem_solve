#include <iostream>

using namespace std;

void solution(int M, int N, int x_d, int y_d)
{
	int visited[40001];
	for(int i = 0; i < 40001;i ++)
		visited[i] = 0;
	int x = x_d;
	int y = (x_d)%N;
	int cnt = x_d+1;
	visited[y] = 1;
	if(y == y_d)
	{
		cout << cnt << "\n";
		return ;
	}
	while(1)
	{
		y = (y + M) % N;
		if(visited[y])
			break;
		cnt += M;
		if(y == y_d)
		{
			cout << cnt << "\n";
			return ;
		}
		visited[y] = 1;
	}
	cout << "-1\n";
}

int main()
{
	int T;
	cin >> T;
	for(int i = 0; i < T; i ++)
	{
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		solution(M, N, x-1, y-1);
	}
}