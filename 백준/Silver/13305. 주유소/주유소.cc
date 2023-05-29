#include <iostream>

using namespace std;

int N;
int length[100000];
int cost[100000];

int main()
{
	cin >> N;
	for(int i = 0; i < N-1; i ++)
		cin >> length[i];
	for(int i = 0; i < N; i ++)
		cin >> cost[i];

	long long sum = 0;
	int mn = 1000000001;
	for(int i = 0; i < N-1; i++)
	{
		if(cost[i] < mn)
			mn = cost[i];
		sum += mn * length[i];
	}
	cout << sum << endl;
}