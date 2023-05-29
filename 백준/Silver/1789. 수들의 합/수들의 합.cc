#include <iostream>

using namespace std;

long long S;



int main()
{
	cin >> S;
	long long sum = 0;
	int i = 1;
	for(;; i ++)
	{
		sum += i;
		if(sum > S)
			break;
	}
	i --;
	cout << i << endl;
}