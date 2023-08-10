#include <iostream>

using namespace std;

int map[102][102];


void fillMap(int y, int x)
{
	for(int j = 0; j < 10; j ++)
		for(int i = 0; i < 10; i++)
			map[y+j][x+i] = 1;
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main()
{
	int N;
	cin >> N;
	int answer = 0;
	for(int i = 0; i < N; i++)
	{
		int y, x;
		cin >> y >> x;
		fillMap(y, x);
	}
	for(int j = 0; j < 100; j++)
	{
		for(int i = 0; i < 100; i++)
		{
			if(map[j][i])
			{
				for(int k = 0; k < 4; k++)
				{
					int nj = j + dy[k];
					int ni = i + dx[k];
					if(map[nj][ni] == 0)
						answer ++;
				}
			}
		}
	}
	cout << answer << endl;
}