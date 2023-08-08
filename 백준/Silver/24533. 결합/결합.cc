#include <iostream>

using namespace std;

int N;

int main()
{
	cin >> N;
	long long x = 0;
	long long y = 0;
	long long E = 0;
	for(int i = 0; i < N; i++)
	{
		long long a, b;
		cin >> a >> b;
		E += a * y + b * x;
		x += a;
		y += b;
	}
	cout << E << endl;
}