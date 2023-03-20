#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N, M;

int map[100][70];

int check_map[100][70];


int answer;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void same_dfs(int i, int j, vector<pair<int, int> > &vt)
{
	check_map[i][j] = 1;
	vt.push_back(make_pair(i, j));
	for(int k = 0; k < 8; k ++)
	{
		if(i + dx[k] < 0 || i + dx[k] >= N)
			continue;
		if(j + dy[k] < 0 || j + dy[k] >= M)
			continue;
		if(map[i][j] == map[i+dx[k]][j+dy[k]] && check_map[i+dx[k]][j+dy[k]] == 0)
		{
			same_dfs(i+dx[k], j+dy[k], vt);
		}
	}
}

void check_head(vector<pair<int, int> > &vt)
{
	int flag = 1;

	for(int x = 0; x < vt.size(); x ++)
	{
		int i = vt[x].first;
		int j = vt[x].second;
		for(int k = 0; k < 8; k ++)
		{
			if(i + dx[k] < 0 || i + dx[k] >= N)
				continue;
			if(j + dy[k] < 0 || j + dy[k] >= M)
				continue;
			if(map[i+dx[k]][j+dy[k]] > map[i][j])
			{
				flag = 0;
			}
		}
		if(!flag)
		{
			break;
		}
	}
	if(flag)
	{
			// for(int i = 0; i < vt.size(); i ++)
			// {
			// 	int x = vt[i].first;
			// 	int y = vt[i].second;
			// 	//cout << x << " " << y << endl;
			// }
		//answer += vt.size();
		answer ++;
	}
}

void check(int i, int j)
{
	vector<pair<int, int> > vt;
	same_dfs(i, j, vt);
	check_head(vt);
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i < N; i ++)
	{
		for(int j = 0; j < M; j ++)
		{
			cin >> map[i][j];
		}
	}
	for(int i = 0; i < N; i ++)
	{
		for(int j = 0; j < M; j ++)
		{
			if(check_map[i][j] == 0)
			{
				check(i, j);
			}
		}
	}
	cout << answer << endl;
}
