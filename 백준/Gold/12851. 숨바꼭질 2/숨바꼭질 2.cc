#include <iostream>
#include <queue>

using namespace std;

int N, K;

queue<pair<int, int> > que;

typedef struct tmp
{
	int count;
	int time;
}tmp;

tmp ar[100001];

int flag = -1;

void bfs()
{
	que.push(pair<int, int>(N, 0));
	while(1)
	{
		if(que.empty())
			break ;
		int index = que.front().first;
		int time = que.front().second;
		que.pop();
		if(index < 0 || index > 100000)
			continue;
		if(!ar[index].count)
		{
			ar[index].time = time;
			ar[index].count ++;
		}
		else if(ar[index].time == time)
		{
			ar[index].count ++;
		}
		else
			continue;
		que.push(pair<int, int>(index+1, time+1));
		que.push(pair<int, int>(index-1, time+1));
		que.push(pair<int, int>(index*2, time+1));
	}
}

int main()
{
	cin >> N >> K;
	bfs();
	cout << ar[K].time << endl;
	cout << ar[K].count << endl;
}