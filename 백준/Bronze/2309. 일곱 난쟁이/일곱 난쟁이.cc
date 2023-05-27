#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ar[9];

int n = 9;
int k = 7;
vector<int> vt;
int flag = 0;

void combi(int start, vector<int> &b)
{
	if(flag)
		return ;
	if(b.size() == k)
	{
		int sum = 0;
		for(int i = 0; i < k; i ++)
		{
			sum += ar[vt[i]];
		}
		if(sum == 100)
		{
			for(int i = 0; i < k; i ++)
				cout << ar[vt[i]] << "\n";
			flag = 1;
		}
		return ;
	}
	for(int i = start + 1; i < n; i ++)
	{
		b.push_back(i);
		combi(i, b);
		b.pop_back();
	}
}

int main()
{
	for(int i = 0; i < 9; i ++)
		cin >> ar[i];
	sort(ar, ar+9);
	combi(-1, vt);
}