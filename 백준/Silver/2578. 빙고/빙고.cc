#include <iostream>
#include <cstdlib>

using namespace std;

int mp[5][5];
int visited[5][5];

int check_cnt()
{
	int cnt = 0;
	for(int j = 0; j < 5; j++)
	{
		int tmp = 0;
		for(int i = 0; i < 5; i ++)
		{
			if(visited[j][i] == 0)
				break;
			tmp ++;
		}
		if(tmp == 5)
			cnt ++;
	}
	for(int j = 0; j < 5; j++)
	{
		int tmp = 0;
		for(int i = 0; i < 5; i ++)
		{
			if(visited[i][j] == 0)
				break;
			tmp ++;
		}
		if(tmp == 5)
			cnt ++;
	}
	int tmp = 0;
	for(int i = 0; i < 5; i ++)
	{
		if(visited[i][i] == 0)
			break;
		tmp ++;
	}
	if(tmp == 5)
		cnt ++;
	
	tmp = 0;
	for(int i = 0; i < 5; i ++)
	{
		if(visited[i][4-i] == 0)
			break;
		tmp ++;
	}
	if(tmp == 5)
		cnt ++;
	return cnt;
}

void solution(int num)
{
	int y, x;
	for(int j = 0; j < 5; j++)
		for(int i = 0; i < 5; i ++)
		{
			if(mp[j][i] == num)
			{
				y = j;
				x = i;
			}
		}
	visited[y][x] = 1;
	
	int cnt = 0;
}

int main()
{
	for(int j = 0; j < 5; j++)
		for(int i = 0; i < 5; i ++)
			cin >> mp[j][i];
	for(int j = 1; j <= 25; j ++)
	{
		int num;
		cin >> num;
		solution(num);
		if(check_cnt() >= 3)
		{
			cout << j << endl;
			return 0;
		}
	}
}