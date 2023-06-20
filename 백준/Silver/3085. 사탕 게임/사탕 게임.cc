#include <iostream>
#include <algorithm>

using namespace std;

int N;
char mp[51][51];

int answer;

void m_swap(int j1, int i1, int j2, int i2)
{
	char tmp;
	tmp = mp[j1][i1];
	mp[j1][i1] = mp[j2][i2];
	mp[j2][i2] = tmp;
}

void check()
{
	for(int j = 0; j< N; j ++)
	{
		char before = mp[j][0];
		int cnt = 1;
		for(int i = 1; i < N; i ++)
		{
			if(before == mp[j][i])
				cnt ++;
			else
				cnt = 1;
			before = mp[j][i];
			answer = max(answer, cnt);
		}
	}
	for(int i = 0; i< N; i ++)
	{
		char before = mp[0][i];
		int cnt = 1;
		for(int j = 1; j < N; j ++)
		{
			if(before == mp[j][i])
				cnt ++;
			else
				cnt = 1;
			before = mp[j][i];
			answer = max(answer, cnt);
		}
	}
}

int main()
{
	cin >> N;
	for(int j = 0; j < N; j++)
			cin >> mp[j];
	
	for(int j = 0; j < N; j ++)
	{
		for(int i = 0; i < N; i ++)
		{
			if(j != N-1 && mp[j][i] != mp[j+1][i])
			{
				m_swap(j, i, j+1, i);
				check();
				m_swap(j, i, j+1, i);
			}
			if(i != N-1 && mp[j][i] != mp[j][i+1])
			{
				m_swap(j, i, j, i+1);
				check();
				m_swap(j, i, j, i+1);
			}
		}
	}
	cout << answer << endl;
}