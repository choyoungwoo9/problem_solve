#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int N;

int mp[100][100];
char ar[10001];

//D -> + 
//L -> -
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void game_start()
{
	int y = 0;
	int x = 0;
	int time = 0;
	deque<int> deq;
	mp[y][x] = 1;
	deq.push_back(x*100+y);
	int dir = 0;
	while(1)
	{
		time ++;
		if(ar[time-1] == 'D')
			dir = (dir + 1)%4;
		else if(ar[time-1] == 'L')
		{
			if(dir == 0)
				dir = 3;
			else
				dir --;
		}
		x += dx[dir];
		y += dy[dir];
		//cout << y << " " << x << " " << time << " " << dir << endl;
		if(x < 0 || x >= N || y < 0 || y >= N || mp[y][x] == 1)
		{
			cout << time << endl;
			return ;
		}

		if(mp[y][x] == 2)
		{
			mp[y][x] = 1;
			deq.push_back(y*100+x);
		}
		else
		{
			mp[y][x] = 1;
			deq.push_back(y*100+x);
			mp[deq.front() / 100][deq.front()%100] = 0;
			deq.pop_front();
		}
		// for(int i = 0; i < N; i ++)
		// {
		// 	for(int j = 0; j < N; j ++)
		// 		cout << mp[i][j];
		// 	cout << endl;
		// }

	}
}

int main()
{
	cin >> N;
	int K;
	cin >> K;
	for(int i = 0; i < K; i ++)
	{
		int c, r;
		cin >> c >> r;
		mp[c-1][r-1] = 2;
	}
	int L;
	cin >> L;
	for(int i = 0; i < L; i ++)
	{
		int t;
		cin >> t;
		cin >> ar[t];
	}
	game_start();
}