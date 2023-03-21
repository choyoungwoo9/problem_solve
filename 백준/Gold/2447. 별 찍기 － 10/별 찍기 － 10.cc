#include <iostream>
#include <cmath>

using namespace std;

int N, k;

//bool map[3][3];
bool map[3*3*3*3*3*3*3*3][3*3*3*3*3*3*3*3];

void find_k()
{
	k = 1;
	int tmp = 3;
	while(tmp != N)
	{
		k++;
		tmp = tmp * 3;
	}
}

void make_basic_level(int i, int j)
{
	map[i][j] = 1;
	map[i][j+1] = 1;
	map[i][j+2] = 1;
	map[i+1][j] = 1;
	map[i+1][j+1] = 0;
	map[i+1][j+2] = 1;
	map[i+2][j] = 1;
	map[i+2][j+1] = 1;
	map[i+2][j+2] = 1;
}

int dx[8] = {0, 0, 0, 1, 1, 2, 2, 2};
int dy[8] = {0, 1, 2, 0, 2, 0, 1, 2};

void make_map(int i, int j, int level)
{
	if(level == 1)
	{
		make_basic_level(i, j);
		return ;
	}
	int power = pow(3, level - 1);
	for(int k = 0; k < 8; k ++)
	{
		make_map(i + dx[k] * power, j + dy[k] * power, level-1);
	}
}

void print_map()
{
	for(int i = 0; i < N; i ++)
	{
		for(int j = 0; j < N; j ++)
		{
			if(map[i][j])
				cout << '*';
			else
				cout << " ";
		}
		cout << "\n";
	}
}

int main()
{
	cin >> N;
	find_k();
	make_map(0, 0, k);
	print_map();
}