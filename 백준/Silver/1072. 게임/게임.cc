#include <iostream>

using namespace std;

long long X, Y;
double Z;

int getPercent(long long A, long long B)
{
	long long percent = 100 * B / A;
	return percent;
}

int main()
{
	cin >> X >> Y;
	int first = getPercent(X, Y);
	if(first >= 99)
	{
		cout << -1 << endl;
		return 0;
	}
	long long cnt = 0;

	while(1)
	{
		cnt = cnt + 10000;
		if(first != getPercent(X+cnt, Y+cnt))
		{
			while(first != getPercent(X+cnt, Y+cnt))
			{
				cnt --;
			}
			cout << cnt+1 << endl;
			return 0;
		}
	}
}