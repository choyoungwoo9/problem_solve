#include <iostream>

using namespace std;

int ar[10][7] = {{1, 1, 1, 0, 1, 1, 1}, {0, 0, 1, 0, 0, 1, 0}, {1, 0, 1, 1, 1, 0, 1}, {1, 0, 1, 1, 0, 1, 1}, {0, 1, 1, 1, 0, 1, 0}
				,{1, 1, 0, 1, 0, 1, 1}, {1, 1, 0, 1, 1, 1, 1}, {1, 0, 1, 0, 0, 1, 0}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 1, 1}};

int diff[10][10];

int N, K, P, X;

int answer;

void make_i(int idx)
{
	int place = 10;
	int cnt = 0;
	for(int i = 0; i < K; i++)
	{
		cnt += diff[(X%place)/(place/10)][(idx%place)/(place/10)];
		place = place * 10;
	}
	// cout << cnt << " " << idx << endl;
	if(cnt <= P)
	{
		answer ++;
	}
}

int main()
{
	for(int i = 0; i < 10; i ++)
	{
		for(int j = 0; j < 10; j ++)
		{
			int sum = 0;
			for(int k = 0; k < 7; k ++)
			{
				if(ar[i][k] != ar[j][k])
					sum ++;
			}
			diff[i][j] = sum;
		}
	}
	// for(int i = 0; i < 10; i ++)
	// {
	// 	for(int j = 0; j < 10; j++)
	// 		cout << diff[i][j] << " ";
	// 	cout << endl;
	// }
	cin >> N >> K >> P >> X;

	for(int i = 1; i <= N; i++)
	{
		if(i == X)
			continue;
		make_i(i);
	}
	cout << answer << endl;
}