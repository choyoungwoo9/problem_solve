#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;

vector<int> vt;

int is_prime(int num)
{
	for(int i = 2; i * i <= num; i++)
	{
		if(num % i == 0)
			return 0;
	}
	return 1;
}

void make_answer(int num)
{
	int gap = 100000;
	int m_min;
	int m_max;
	for(int i = 0; i < vt.size(); i++)
	{
		for(int j = 0; j < vt.size(); j ++)
		{
			if(vt[i] + vt[j] == num)
			{
				if(abs(vt[i] - vt[j]) < gap)
				{
					gap = abs(vt[i] - vt[j]);
					m_min = min(vt[i], vt[j]);
					m_max = max(vt[i], vt[j]);
				}
			}
		}
	}
	cout << m_min << " " << m_max << "\n";
}

typedef struct tmp
{
	int n1;
	int n2;
}tmp;

tmp ar[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i = 2; i <= 10000; i ++)
	{
		if(is_prime(i))
			vt.push_back(i);
	}
	for(int i = 0; i < vt.size(); i++)
	{
		for(int j = 0; j < vt.size(); j++)
		{
			if(vt[i] + vt[j] > 10000)
				break;
			int sum = vt[i] + vt[j];
			
			if(!ar[sum].n1 || abs(vt[i] - vt[j]) < abs(ar[sum].n1 - ar[sum].n2))
			{
				ar[sum].n1 = min(vt[i], vt[j]);
				ar[sum].n2 = max(vt[i], vt[j]);
			}
		}
	}
	for(int i = 0; i < n; i ++)
	{
		int num;
		cin >> num;
		cout << ar[num].n1 << " " << ar[num].n2 << "\n";
	}
}