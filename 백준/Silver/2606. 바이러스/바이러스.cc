#include <iostream>
#include <vector>

using namespace std;

int N;

vector<int> ComVt[101];
int visited[101];
int answer = 0;

void dfs(int idx)
{
	answer ++;
	visited[idx] = 1;
	for(int i = 0; i < ComVt[idx].size(); i++){
		int next = ComVt[idx][i];
		if(visited[next])
			continue;
		dfs(next);
	}
}

int main()
{
	cin >> N;
	int T;
	cin >> T;
	for(int i = 0; i < T; i++){
		int a, b;
		cin >> a >> b;
		ComVt[a].push_back(b);
		ComVt[b].push_back(a);
	}
	visited[1] = 1;
	dfs(1);
	answer --;
	cout << answer << endl;
}