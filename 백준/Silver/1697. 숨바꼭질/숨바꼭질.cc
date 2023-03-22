#include <iostream>
#include <queue>
using namespace std;

int N, K;

int dp_table[200002];

queue<pair<int, int> > que;

void bfs()
{
	que.push(make_pair(N, 0));
	while(1)
	{
		int cur_index = que.front().first;
		int cur_time = que.front().second;
		que.pop();
		if(cur_index < 0 || cur_index > 200001)
			continue;
		if(dp_table[cur_index] != -1)
			continue;
		dp_table[cur_index] = cur_time;
		if(cur_index == K)
			return ;
		que.push(make_pair(cur_index+1, cur_time+1));
		que.push(make_pair(cur_index-1, cur_time+1));
		que.push(make_pair(cur_index*2, cur_time+1));
	}
}

int main()
{
	cin >> N >> K;
	for(int i = 0; i < 200002; i ++)
	{
		dp_table[i] = -1;
	}
	bfs();
	cout << dp_table[K] << endl;
}