#include <iostream>
#include <vector>
using namespace std;

vector<int> vt[101];

int n;

int start, dest;
int answer = -1;

int visited[101];

void dfs(int idx, int level)
{
	//cout << idx << endl;
	visited[idx] = 1;
	if(idx == dest)
	{
		answer = level;
		return ;
	}
	for(int tmp : vt[idx])
	{
		if(!visited[tmp]){
			dfs(tmp, level+1);
		}
	}
}

int main()
{
	cin >> n;
	cin >> start >> dest;
	int K;
	cin >> K;
	for(int i = 0; i < K; i ++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		vt[n1].push_back(n2);
		vt[n2].push_back(n1);
	}
	dfs(start,0);
	cout << answer << endl;
}