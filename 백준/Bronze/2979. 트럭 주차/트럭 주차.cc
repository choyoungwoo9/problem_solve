#include <iostream>
#include <algorithm>
using namespace std;

int A, B, C;

int ar[101];

int main()
{
	cin >> A >> B >> C;
	for(int i = 0; i < 3; i ++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		
		for(int i = t1; i < t2; i ++)
			ar[i] ++;
	}

	int sum = 0;
	for(int i = 1; i <= 100; i ++)
	{
		if(ar[i] == 1)
			sum += A;
		else if(ar[i] == 2)
			sum += B * 2;
		else if(ar[i] == 3)
			sum += C * 3;
	}
	cout << sum << endl;
}