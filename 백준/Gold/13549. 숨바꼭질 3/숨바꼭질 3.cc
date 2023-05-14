#include <iostream>
#include <queue>

using namespace std;

int N, K;
int ar[100001];
queue<pair<int, int> > que;

void bfs()
{
	que.push(pair<int, int>(N, 0));
	while(!que.empty())
	{
		int index = que.front().first;
		int time = que.front().second;
		que.pop();
		if(index > 100000 || index < 0)
			continue;
		if(ar[index] != -1)
			continue;
		ar[index] = time;
		que.push(pair<int, int>(index+1, time+1));
		que.push(pair<int, int>(index-1, time+1));
		while(index != 0 && index <= 100000)
		{
			if(ar[index] == -1)
			{
				ar[index] = time;
				que.push(pair<int, int>(index+1, time+1));
				que.push(pair<int, int>(index-1, time+1));
			}
			index = index * 2;
		}
	}
}

int main()
{
	cin >> N >> K;
	for(int i = 0; i <= 100000; i ++)
		ar[i] = -1;
	bfs();
	cout << ar[K] << endl;
}