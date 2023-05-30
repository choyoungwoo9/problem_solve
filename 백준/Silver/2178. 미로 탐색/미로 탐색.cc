#include <iostream>
#include <queue>
using namespace std;

char mp[101][102];

int N, M;

class info
{
	public:
		info(int y, int x, int cost)
		{
			this->y = y;
			this->x = x;
			this->cost = cost;
		}
		int y;
		int x;
		int cost;
};

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

queue<info> que;

int answer;

void bfs()
{
	que.push(info(1, 1, 1));
	mp[1][1] = '0';
	while(1)
	{
		int y = que.front().y;
		int x = que.front().x;
		int cost = que.front().cost;
		if(y == N && x == M)
		{
			answer = cost;
			break;
		}
		que.pop();
		for(int i = 0; i < 4; i ++)
		{
			if(y+dy[i] <= 0 || y+dy[i] > N)
				continue;
			if(x+dx[i] <= 0 || x+dx[i] > M)
				continue;
			if(mp[y+dy[i]][x+dx[i]] == '0')
				continue;
			mp[y+dy[i]][x+dx[i]] = '0';
			que.push(info(y+dy[i], x+dx[i], cost+1));
		}
	}
}

int main()
{
	cin >> N >> M;
	for(int j = 1; j <= N; j++)
	{
		cin >> (mp[j] + 1);
	}
	bfs();
	cout << answer << endl;
}