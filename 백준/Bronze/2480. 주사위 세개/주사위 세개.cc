#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int ar[3];
	cin >> ar[0] >> ar[1] >> ar[2];
	sort(ar, ar+3);
	int answer = 0;
	if(ar[0] == ar[1] && ar[1] == ar[2])
	{
		answer = 10000 + ar[0] * 1000;
	}
	else if(ar[0] == ar[1] || ar[1] == ar[2])
	{
		answer = 1000 + ar[1] * 100;	
	}
	else
	{
		answer = 100 * ar[2];
	}
	cout << answer << endl;
}