#include <iostream>

using namespace std;

int main()
{
	int X;
	cin >> X;
	int level = 1;
	int idx = 0;
	int sum = 0;
	while(1)
	{
		sum += level;
		if(sum >= X)
		{
			idx = sum - X;
			break;
		}
		level ++;
	}
	idx ++;

	if(level % 2 == 0)
	{
		cout << level+1-idx << "/" << idx << endl;
	}
	else
	{
		cout << idx  << "/" << level+1-idx << endl;
	}
}