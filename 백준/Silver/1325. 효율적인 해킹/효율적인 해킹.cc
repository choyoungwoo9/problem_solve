#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> node[10001];
int visited[10001];

int N, M;

int hacked[10001];

int dfs(int idx)
{
	visited[idx] = 1;
	int ret = 1;
	for(int tmp : node[idx])
	{
		if(visited[tmp])
			continue;
		ret += dfs(tmp);
	}
	return ret;
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i < M; i ++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		node[n2].push_back(n1);
	}

	for(int i = 1;i <= N; i ++)
	{
		memset(visited, 0, sizeof(visited));
		hacked[i] = dfs(i);
	}
	int mx = 0;
	for(int i = 1; i <= N; i ++)
	{
		if(hacked[i] > mx)
			mx = hacked[i];
	}
	vector<int> vt;
	for(int i = 1; i <= N; i ++)
	{
		if(hacked[i] == mx)
			vt.push_back(i);
	}
	sort(vt.begin(), vt.end());	

	for(int num : vt)
		cout << num << " ";
	cout << endl;
}