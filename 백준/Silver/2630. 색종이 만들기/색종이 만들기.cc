#include <iostream>

using namespace std;

int N;
int w_a;
int b_a;

int mp[128][128];

void dq(int j_idx, int i_idx, int s)
{
	int color = mp[j_idx][i_idx];
	int flag = 1;
	for(int j = 0; j < s; j ++)
	{
		for(int i = 0; i < s; i++)
		{
			if(mp[j_idx+j][i_idx+i] != color)
			{
				flag = 0;
				break;
			}
		}
		if(flag == 0)
			break;
	}
	if(flag == 1)
	{
		if(color == 0)
			w_a ++;
		else
			b_a ++;
	}
	else
	{
		dq(j_idx, i_idx, s/2);
		dq(j_idx + s/2, i_idx, s/2);
		dq(j_idx, i_idx + s/2, s/2);
		dq(j_idx + s/2, i_idx + s/2, s/2);
	}
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i ++)
		for(int j = 0; j < N; j++)
			cin >>mp[i][j];
	dq(0, 0, N);
	cout << w_a << '\n' << b_a << '\n';
}