#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dependency[32001];
vector<int> node[32001];

int N, M;

int main()
{
	cin >> N >> M;

	for(int i = 0; i < M; i ++)
	{
		int a, b;
		cin >> a >> b;
		dependency[b] ++;
		node[a].push_back(b);
	}

	priority_queue<int, vector<int>, greater<int> > que;
	for(int i = 1; i <= N; i++)
	{
		if(!dependency[i])
			que.push(i);
	}
	while(!que.empty())
	{
		int num = que.top();
		que.pop();
		cout << num << " ";
		for(int i = 0; i < node[num].size(); i ++)
		{
			dependency[node[num][i]] --;
			if(!dependency[node[num][i]])
				que.push(node[num][i]);
		}
	}
	cout << "\n";
}