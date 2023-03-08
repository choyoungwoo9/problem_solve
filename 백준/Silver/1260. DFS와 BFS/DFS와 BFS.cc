#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int N, M, V;

int visited[1001];

int map[1001][1001];

stack<int> st;
queue<int> qu;

void dfs(int num)
{
	if(visited[num])
		return;
	visited[num] = 1;
	cout << num << " ";
	for(int i = N; i > 0; i --)
	{
		if(map[num][i])
		{
			//cout << "this "<< num << " " << i << endl;
			st.push(i);
		}
	}
	while(1)
	{
		if(st.empty())
			return ;
		int cur_city = st.top();
		st.pop();
		if(visited[cur_city])
			continue;
		visited[cur_city] = 1;
		cout << cur_city << " ";
		for(int i = N; i > 0; i --)
		{
			if(map[cur_city][i] && !visited[i])
			{
				//cout << "this "<< cur_city << " " << i << endl;
				st.push(i);
			}
		}
	}
}

void bfs(int num)
{
	cout << num << " ";
	visited[num] = 1;
	for(int i = 1; i <= N; i ++)
	{
		if(map[num][i])
			qu.push(i);
	}
	while(1)
	{
		if(qu.empty())
			return ;
		int cur_city = qu.front();
		qu.pop();
		if(visited[cur_city])
			continue;
		visited[cur_city] = 1;
		cout << cur_city << " ";
		for(int i = 1; i <= N; i ++)
		{
			if(map[cur_city][i] && !visited[i])
				qu.push(i);
		}
	}
}

int main()
{
	cin >> N >> M >> V;
	for(int i = 0; i < M; i ++)
	{
		int c_1, c_2;
		cin >> c_1 >> c_2;
		map[c_1][c_2] = 1;
		map[c_2][c_1] = 1;
	}
	dfs(V);
	cout << endl;
	for(int i = 1; i <= N; i ++)
		visited[i] = 0;
	bfs(V);
}