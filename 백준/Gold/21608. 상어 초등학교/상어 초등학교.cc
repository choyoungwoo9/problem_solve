#include <iostream>
#include <queue>

using namespace std;

int N;
int mp[21][21];

int idx;
int like_friend[500][4];

typedef struct info{
	int friend_cnt;
	int empty_cnt;
	int y;
	int x;
}info;

struct compare{
	bool operator()(const info &a, const info &b)
	{
		if(a.friend_cnt != b.friend_cnt)
			return a.friend_cnt < b.friend_cnt;
		if(a.empty_cnt != b.empty_cnt)
			return a.empty_cnt < b.empty_cnt;
		if(a.y != b.y)
			return a.y > b.y;
		return a.x > b.x;
	}
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int get_friend(int y, int x)
{
	int ret = 0;
	for(int i = 0; i < 4; i ++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= N || nx < 0 || nx >= N)
			continue;
		for(int k = 0; k < 4; k ++)
		{
			if(mp[ny][nx] == like_friend[idx][k])
			{
				ret ++;
				break;
			}
		}
	}
	return ret;
}

int get_empty(int y, int x)
{
	int ret = 0;
	for(int i = 0; i < 4; i ++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= N || nx < 0 || nx >= N)
			continue;
		if(mp[ny][nx] == 0)
		{
			ret ++;
		}
	}
	return ret;
}

void seat()
{
	priority_queue<info, vector<info>, compare> pq;
	for(int j = 0; j < N; j ++)
	{
		for(int i = 0; i < N; i ++)
		{
			if(mp[j][i])
				continue;
			info fo;
			fo.friend_cnt = get_friend(j, i);
			fo.empty_cnt = get_empty(j, i);
			fo.y = j;
			fo.x = i;
			pq.push(fo);
		}
	}
	int y = pq.top().y;
	int x = pq.top().x;
	mp[y][x] = idx;
}

int ar[5] = {0, 1, 10, 100, 1000};

int main()
{
	cin >> N;
	for(int i = 0; i < N * N; i ++)
	{
		cin >> idx;
		for(int j = 0; j < 4; j++)
			cin >> like_friend[idx][j];
		seat();
	}
	// for(int j = 0; j < N; j++)
	// {
	// 	for(int i = 0; i < N; i ++)
	// 		cout << mp[j][i] << " ";
	// 	cout << endl;
	// }

	int answer = 0;
	for(int j = 0; j < N; j++)
	{
		for(int i = 0; i < N; i ++)
		{
			idx = mp[j][i];
			answer += ar[get_friend(j, i)];
			// cout << get_friend(j, i) << endl;
		}
	}
	cout << answer << endl;
}