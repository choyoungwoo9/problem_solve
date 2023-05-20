#include <iostream>

using namespace std;

int N, M;
int r, c, d;
int m_map[50][50];

int answer;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int check_around(int i, int j)
{
	for(int k = 0; k < 4; k ++)
	{
		if(m_map[i+dx[k]][j+dy[k]] == 0)
			return 1;
	}
	return 0;
}

void work(int i, int j, int dir)
{

	if(m_map[i][j] == 0)
	{
		answer ++;
		m_map[i][j] = 2;
	}

	if(check_around(i, j)) //청소 할 곳 있음
	{
		if(dir == 0)
		{
			if(!m_map[i][j-1])
				work(i, j-1, 3);
			else if(!m_map[i+1][j])
				work(i+1, j, 2);
			else if(!m_map[i][j+1])
				work(i, j+1, 1);
			else if(!m_map[i-1][j])
				work(i-1, j, 0);
		}
		else if(dir == 1)
		{
			if(!m_map[i-1][j])
				work(i-1, j, 0);
			else if(!m_map[i][j-1])
				work(i, j-1, 3);
			else if(!m_map[i+1][j])
				work(i+1, j, 2);
			else if(!m_map[i][j+1])
				work(i, j+1, 1);
		}
		else if(dir == 2)
		{
			if(!m_map[i][j+1])
				work(i, j+1, 1);
			else if(!m_map[i-1][j])
				work(i-1, j, 0);
			else if(!m_map[i][j-1])
				work(i, j-1, 3);
			else if(!m_map[i+1][j])
				work(i+1, j, 2);
		}
		else if(dir == 3)
		{
			if(!m_map[i+1][j])
				work(i+1, j, 2);
			else if(!m_map[i][j+1])
				work(i, j+1, 1);
			else if(!m_map[i-1][j])
				work(i-1, j, 0);
			else if(!m_map[i][j-1])
				work(i, j-1, 3);
		}
	}
	else
	{
		if(dir == 0)
		{
			if(m_map[i+1][j] == 1)
				return ;
			work(i+1, j, dir);
		}
		else if(dir == 1)
		{
			if(m_map[i][j-1] == 1)
				return ;
			work(i, j-1, dir);
		}
		else if(dir == 2)
		{
			if(m_map[i-1][j] == 1)
				return ;
			work(i-1, j, dir);
		}
		else if(dir == 3)
		{
			if(m_map[i][j+1] == 1)
				return ;
			work(i, j+1, dir);
		}
	}
}

int main()
{
	cin >> N >> M;
	cin >> r >> c >> d;
	for(int i = 0; i < N; i ++)
	{
		for(int j = 0; j < M; j ++)
			cin >> m_map[i][j];
	}
	work(r, c, d);
	cout << answer << endl;
}