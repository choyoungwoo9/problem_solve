#include <iostream>

using namespace std;


int main()
{
	int X;
	cin >> X;
	int now = 64;
	int sum = 0;
	int answer = 0;
	while(1)
	{
		if(now + sum > X)
		{
			now = now / 2;
			continue;
		}
		else if(now + sum == X)
		{
			answer ++;
			break;
		}
		else if(now + sum < X)
		{
			sum += now;
			now = now / 2;
			answer ++;
			continue;
		}
	}
	cout << answer << endl;
}