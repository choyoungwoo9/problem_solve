#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dependency[32001];
vector<int> node[32001];
int N, M;
queue<int> que;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < M; i ++)
	{
		int a, b;
		cin >> a >> b;
		dependency[b] ++;
		node[a].push_back(b);
	}
	
	for(int i = 1; i <= N; i ++)
	{
		if(!dependency[i])
			que.push(i);
	}
	while(!que.empty())
	{
		int index = que.front();
		que.pop();
		cout << index << " ";
		for(int i = 0; i < node[index].size(); i ++)
		{
			dependency[node[index][i]] --;
			if(!dependency[node[index][i]])
				que.push(node[index][i]);
		}
	}
	cout << endl;
}