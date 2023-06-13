#include <iostream>

using namespace std;

int mp[10][10];
int N;

int answer = 3001;

int out_check(int value)
{
	int j = value / N;
	int i = value % N;
	if(i == 0 || j == 0 || i == N-1 || j == N-1)
		return 1;
	return 0;
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int duplicate_check(int value1, int value2)
{
	int ar[5] = {value1, value1+1, value1-1, value1+N, value1-N};
	int ar2[5] = {value2, value2+1, value2-1, value2+N, value2-N};
	for(int i = 0; i < 5; i ++)
	{
		for(int j = 0; j < 5; j ++)
			if(ar[i] == ar2[j])
				return 1;
	}
	return 0;
}

int get_cost(int value)
{
	int j = value / N;
	int i = value % N;
	int ret = 0;
	ret += mp[j][i];
	for(int k = 0; k < 4; k ++)
	{
		ret += mp[j+dy[k]][i+dx[k]];
	}
	return ret;
}

void check(int a, int b, int c)
{
	if(out_check(a) || out_check(b) || out_check(c))
		return;
	if(duplicate_check(a, b) || duplicate_check(a, c) || duplicate_check(b, c))
		return;
	answer = min(answer, get_cost(a) + get_cost(b) + get_cost(c));
}

int main()
{
	cin >> N;
	for(int j = 0; j < N; j ++)
		for(int i = 0; i < N; i ++)
			cin >> mp[j][i];
	
	for(int i = 0; i < N*N; i ++)
		for(int j = i+1; j < N*N; j++)
			for(int k = j+1; k < N*N; k ++)
				check(i, j, k);
	cout << answer << endl;
}