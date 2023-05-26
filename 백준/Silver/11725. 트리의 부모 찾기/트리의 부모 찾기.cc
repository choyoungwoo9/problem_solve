#include <iostream>
#include <vector>

using namespace std;

int N;

vector<int> vt[100001];
int visited[100001];

void dfs(int num, int parent)
{
	visited[num] = parent;
	for(int i = 0; i < vt[num].size(); i ++)
	{
		if(visited[vt[num][i]])
			continue;
		dfs(vt[num][i], num);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for(int i = 0; i < N-1; i ++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		vt[n1].push_back(n2);
		vt[n2].push_back(n1);
	}
	dfs(1, -1);

	for(int i = 2; i <= N; i ++)
	{
		cout << visited[i] << " ";
	}
	cout << "\n";
}