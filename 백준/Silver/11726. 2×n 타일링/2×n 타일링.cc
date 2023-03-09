#include <iostream>
using namespace std;

typedef struct dp
{
	unsigned long long last_vertical;
	unsigned long long last_horizontal;
}	dp;

dp table[10001];

int main()
{
	table[1].last_vertical = 1;
	table[1].last_horizontal = 0;
	int n;
	cin >> n;
	for(int i = 2; i <= n; i ++)
	{
		table[i].last_vertical = (table[i-1].last_horizontal + table[i-1].last_vertical) % 10007;
		table[i].last_horizontal = table[i-1].last_vertical;
	}
	cout << (table[n].last_vertical + table[n].last_horizontal) % 10007 << endl;
}