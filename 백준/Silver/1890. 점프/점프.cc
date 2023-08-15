#include <iostream>

using namespace std;

int N;

//인풋 (weight)
int wMap[100][100];

//경로개수 마킹
unsigned long long cMap[100][100];

void jump(int y, int x)
{
	int weight = wMap[y][x];
	if(weight == 0)
		return ;
	unsigned long long cnt= cMap[y][x];
	int ny = y + weight;
	int nx = x + weight;
	if(ny < N)
		cMap[ny][x] += cnt;
	if(nx < N)
		cMap[y][nx] += cnt;
}

void markMap()
{
	cMap[0][0] = 1;
	for(int i = 0; i < N; i++)
	{
		jump(i, i);
		for(int j = i+1; j < N; j++)
			jump(i, j);
		for(int j = i+1; j < N; j++)
			jump(j, i);
	}
}

int main()
{
	cin >> N;
	for(int j = 0; j < N; j++)
	{
		for(int i = 0; i < N; i++)
			cin >> wMap[j][i];
	}
	
	markMap();
	// for(int i = 0; i < N; i++)
	// {
	// 	for(int j = 0; j < N ;j++)
	// 		cout << cMap[i][j];
	// 	cout << endl;
	// }
	cout << cMap[N-1][N-1] << endl;
}