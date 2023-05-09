#include <iostream>

int n;
using namespace std;

int ar[10000];


int answer = 0;

int m_max(int a, int b)
{
	if(a > b)
		return a;
	return b;
}

void back_tracking()
{
	int s0 = 0;
	int s1 = 0;
	int s2 = 0;
	int tmp0;
	int tmp1;
	int tmp2;
	for(int i = 0; i < n; i ++)
	{
		tmp0 = s0;
		tmp1 = s1;
		tmp2 = s2;
		s1 = tmp0+ar[i];
		if(tmp1)
			s2 = tmp1+ar[i];
		s0 = m_max(tmp0, m_max(tmp1, tmp2));
	}
	answer = m_max(s0, m_max(s1, s2));
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		cin >> ar[i];
	}
	back_tracking();
	cout << answer << endl;
}