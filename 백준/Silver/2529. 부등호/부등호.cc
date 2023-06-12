#include <iostream>

using namespace std;

int visited[10];
int answer[10];

int answer2[10];
int N;

char input[9];
int flag = 0;

void dfs(int idx)
{
	if(idx == N && !flag)
	{
		for(int i = 0; i <= N; i ++)
			cout << answer[i];
		cout << endl;
		flag = 1;
	}
	else if(idx == N)
	{
		for(int i = 0; i <= N; i ++)
			answer2[i] = answer[i];
	}
	for(int i = 9; i >= 0; i --)
	{
		if(visited[i])
			continue;
		if(input[idx] == '<')
		{
			if(i <= answer[idx])
			{
				continue;
			}
		}
		else if(input[idx] == '>')
		{
			if(i >= answer[idx])
				continue;
		}
		visited[i] = 1;
		answer[idx+1] = i;
		dfs(idx+1);
		visited[i] = 0;
	}
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i ++)
		cin >> input[i];
	for(int i = 9; i >= 0; i --)
	{
		answer[0] = i;
		visited[i] = 1;
		dfs(0);
		visited[i] = 0;
	}
	for(int i = 0; i <= N; i ++)
		cout << answer2[i];
	cout << endl;
}