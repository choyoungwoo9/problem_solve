#include <iostream>

using namespace std;

int N;

int ar[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int input[10];

void m_swap(int *i, int *j)
{
	int tmp = *i;
	*i = *j;
	*j = tmp;
}

void is_valid()
{
	for(int i = 0; i < N; i ++)
	{
		int sum = 0;
		for(int j = 0; j < i; j++)
		{
			// cout << i << " here\n";
			if(ar[j] > ar[i])
				sum ++;
		}
		if(input[ar[i]] == sum)
			continue;
		else
			return;
	}
	for(int i = 0; i < N; i++)
		cout << ar[i] + 1 << " ";
	cout << endl;
}

void permu(int depth)
{
	if(depth == N)
	{
		is_valid();
		return ;
	}
	for(int i = depth; i < N; i ++)
	{
		m_swap(ar+depth, ar+i);
		permu(depth+1);
		m_swap(ar+depth, ar+i);
	}
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		cin >> input[i];
	}
	permu(0);
	// for(int i = 0; i < N; i ++)
	// 	cout << ar[i] << " ";
	// cout << endl;
}