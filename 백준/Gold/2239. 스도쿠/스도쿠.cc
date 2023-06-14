#include <iostream>

using namespace std;

int visited[10];

char input[9][10];

int check_col(int y, int x, int num)
{
	for(int i = 0; i < 9; i ++)
	{
		if(input[y][i] == num+'0')
			return 0;
	}
	return 1;
}

int check_row(int y, int x, int num)
{
	for(int i = 0; i < 9; i ++)
	{
		if(input[i][x] == num+'0')
			return 0;
	}
	return 1;
}

int check_square(int y, int x, int num)
{
	int y_team = y / 3;
	int x_team = x / 3;
	for(int j = 0; j < 3; j ++)
	{
		for(int i = 0; i < 3; i ++)
		{
			if(input[y_team * 3 + j][x_team * 3 + i] == num + '0')
				return 0;
		}
	}
	return 1;
}

int dfs(int idx)
{
	int y = idx / 9;
	int x = idx % 9;
	//cout << y << " " << x << " " << num << endl;
	if(y == 9 && x == 0)
		return 1;
	if(input[y][x] == '0')
	{
		for(int i = 1; i <= 9; i ++)
		{
			if(!check_col(y, x, i) || !check_row(y, x, i) || !check_square(y, x, i))
				continue;
			input[y][x] = i + '0';
			if(dfs(idx+1))
				return 1;
			input[y][x] = '0';
		}
	}
	else
	{
		if(dfs(idx+1))
			return 1;
	}
	return 0;
}

int main()
{
	for(int j = 0; j < 9; j ++)
	{
		cin >> input[j];
	}
	dfs(0);
	for(int j = 0; j < 9; j ++)
	{
		cout << input[j] << "\n";
	}
}