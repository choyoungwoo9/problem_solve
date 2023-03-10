#include <iostream>

using namespace std;

int ar[100000];

int sum;
int ar_count;

int main()
{
	int K;
	cin >> K;
	for(int i = 0; i < K; i ++)
	{
		int num;
		cin >> num;
		if(num == 0)
		{
			sum -= ar[--ar_count];
		}
		else
		{
			sum += num;
			ar[ar_count++] = num;
		}
	}
	cout << sum << endl;
}