#include <iostream>

using namespace std;

int g_case[5];

int N;
int mp[20][20];

int answer = 0;
int tmp[20][20];

void up()
{
	for(int i = 0; i < N; i ++)
	{
		int before_num = 0;
		int before_j = -1;
		for(int j = 0; j < N; j ++)
		{
			if(tmp[j][i] == 0)
				continue;
			if(before_num == 0 || before_num != tmp[j][i])
			{
				before_num = tmp[j][i];
				before_j = j;
				continue;
			}
			tmp[before_j][i] = tmp[before_j][i] * 2;
			tmp[j][i] = 0;
			before_num = 0;
			before_j = -1;
		}
	}

	for(int i = 0; i < N; i ++)
	{
		for(int j = N-1; j >= 0; j --)
		{
			if(tmp[j][i] == 0)
			{
				for(int k = j+1; k < N; k ++)
				{
					tmp[k-1][i] = tmp[k][i];
					tmp[k][i] = 0;
				}
			}
		}
	}

}

void down()
{
	for(int i = 0; i < N; i ++)
	{
		int before_num = 0;
		int before_j = -1;
		for(int j = N-1; j >= 0; j --)
		{
			if(tmp[j][i] == 0)
				continue;
			if(before_num == 0 || before_num != tmp[j][i])
			{
				before_num = tmp[j][i];
				before_j = j;
				continue;
			}
			tmp[before_j][i] = tmp[before_j][i] * 2;
			tmp[j][i] = 0;
			before_num = 0;
			before_j = -1;
		}
	}

	for(int i = 0; i < N; i ++)
	{
		for(int j = 0; j < N; j ++)
		{
			if(tmp[j][i] == 0)
			{
				for(int k = j-1; k >= 0; k --)
				{
					tmp[k+1][i] = tmp[k][i];
					tmp[k][i] = 0;
				}
			}
		}
	}
}

void left()
{
	for(int j = 0; j < N; j ++)
	{
		int before_num = 0;
		int before_i = -1;
		for(int i = 0; i < N; i ++)
		{
			if(tmp[j][i] == 0)
				continue;
			if(before_num == 0 || before_num != tmp[j][i])
			{
				before_num = tmp[j][i];
				before_i = i;
				continue;
			}
			tmp[j][before_i] = tmp[j][before_i] * 2;
			tmp[j][i] = 0;
			before_num = 0;
			before_i = -1;
		}
	}

	for(int j = 0; j < N; j ++)
	{
		for(int i = N-1; i >= 0; i --)
		{
			if(tmp[j][i] == 0)
			{
				for(int k = i+1; k < N; k ++)
				{
					tmp[j][k-1] = tmp[j][k];
					tmp[j][k] = 0;
				}
			}
		}
	}
}

void right()
{
	for(int j = 0; j < N; j ++)
	{
		int before_num = 0;
		int before_i = -1;
		for(int i = N-1; i >= 0; i --)
		{
			if(tmp[j][i] == 0)
				continue;
			if(before_num == 0 || before_num != tmp[j][i])
			{
				before_num = tmp[j][i];
				before_i = i;
				continue;
			}
			tmp[j][before_i] = tmp[j][before_i] * 2;
			tmp[j][i] = 0;
			before_num = 0;
			before_i = -1;
		}
	}

	for(int j = 0; j < N; j ++)
	{
		for(int i = 0; i < N; i ++)
		{
			if(tmp[j][i] == 0)
			{
				for(int k = i-1; k >= 0; k --)
				{
					tmp[j][k+1] = tmp[j][k];
					tmp[j][k] = 0;
				}
			}
		}
	}
}

void do_case()
{
	for(int j = 0; j < N; j++)
	{
		for(int i = 0; i < N; i ++)
			tmp[j][i] = mp[j][i];
	}
	for(int i = 0; i < 5; i ++)
	{
		if(g_case[i] == 0)
			up();
		else if(g_case[i] == 1)
			down();
		else if(g_case[i] == 2)
			left();
		else if(g_case[i] == 3)
			right();
	}

	for(int j = 0; j < N; j++)
	{
		for(int i = 0; i < N; i ++)
		{
			answer = max(answer, tmp[j][i]);
		}
	}
	// for(int i = 0; i < 5; i ++)
	// 	cout << g_case[i] << " ";
	// cout << endl;
	// for(int j = 0; j < N; j++)
	// {
	// 	for(int i = 0; i < N; i ++)
	// 	{
	// 		cout << tmp[j][i] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
}

void make_case(int depth)
{
	if(depth == 5)
	{
		do_case();
		return;
	}
	for(int i = 0; i <4; i ++)
	{
		g_case[depth] = i;
		make_case(depth+1);
	}
}

int main()
{
	cin >> N;
	for(int j = 0; j < N; j ++)
		for(int i = 0; i < N; i ++)
			cin >> mp[j][i];
	make_case(0);
	cout << answer << endl;
}