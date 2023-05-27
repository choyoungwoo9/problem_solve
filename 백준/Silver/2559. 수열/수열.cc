#include <iostream>

using namespace std;

int N, K;

int ar[100000];

int main()
{
	cin >> N >> K;
	for(int i = 0; i < N; i ++)
		cin >> ar[i];
	
	int sum = 0;
	int mx = -2000000000;
	for(int i = 0; i < N; i ++)
	{
		if(i < K - 1)
		{
			sum += ar[i];
			continue;
		}
		sum += ar[i];
		if(mx < sum)
			mx = sum;
		sum -= ar[i-K+1];
	}
	cout << mx << endl;
}