#include <iostream>
#include <queue>
using namespace std;

typedef struct info
{
	int count;
	int parent;
}	info;

info ar[1000001];
int N;

queue<pair<pair<int, int>, int> > que;

void bfs()
{
	que.push(make_pair(make_pair(N, 0), N+1));
	while(1)
	{
		int cur_num = que.front().first.first;
		int cur_count = que.front().first.second;
		int cur_parent = que.front().second;
		que.pop();
		if(ar[cur_num].count)
			continue;
		ar[cur_num].count = cur_count;
		ar[cur_num].parent = cur_parent;
		if(cur_num == 1)
			return ;
		if(cur_num % 3 == 0)
			que.push(make_pair(make_pair(cur_num/3, cur_count+1), cur_num));
		if(cur_num % 2 == 0)
			que.push(make_pair(make_pair(cur_num/2, cur_count+1), cur_num));
		que.push(make_pair(make_pair(cur_num-1, cur_count+1), cur_num));
	}
}

int answer[1000001];

int main()
{
	cin >> N;
	bfs();
	int ans_count = ar[1].count;
	cout << ans_count << endl;
	int num = 1;
	for(int i = ans_count; i >= 0; i --)
	{
		answer[i] = num;
		num = ar[num].parent;
	}
	for(int i = 0; i <= ans_count; i ++)
		cout << answer[i] << " ";
	cout << endl;
}