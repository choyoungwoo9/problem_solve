#include <iostream>

using namespace std;

int my_map[101][101];

int N;

int map_meta[101][101];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void my_dfs(int i, int j)
{
	map_meta[i][j] = 1;
	for(int k = 0; k < 4; k ++)
	{
		if(i + dx[k] >= N || i + dx[k] < 0)
			continue;
		if(j + dy[k] >= N || j + dy[k] < 0)
			continue;
		if(map_meta[i+dx[k]][j+dy[k]])
			continue;
		my_dfs(i + dx[k], j + dy[k]);
	}
}

int my_max = 0;

int main()
{
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		for(int j = 0; j < N; j ++)
			cin >> my_map[i][j];
	}
	
	for(int height = 0; height < 101; height ++)
	{
		for(int i = 0; i < N; i ++)
		{
			for(int j = 0; j < N; j ++)
			{
				map_meta[i][j] = 0;
				if(my_map[i][j] <= height)
					map_meta[i][j] = 1;
			}
		}
		int safe_count = 0;
		for(int i = 0; i < N; i ++)
		{
			for(int j = 0; j < N; j ++)
			{
				if(map_meta[i][j])
					continue;
				safe_count ++;
				my_dfs(i, j);
			}
		}
		if(my_max < safe_count)
			my_max = safe_count;
	}
	cout << my_max << endl;
}
