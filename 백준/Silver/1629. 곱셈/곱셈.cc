#include <iostream>

using namespace std;

int A, B, C;

int solve(int num)
{
	if(num == 1)
		return A % C;
	unsigned long long ret;
	if(num % 2 == 0)
	{
		ret = solve(num / 2);
		ret = ret * ret % C;
	}
	else
	{
		ret = solve(num / 2);
		ret = ret * ret % C;
		ret = ret * A % C;
	}
	return ret;
}

int main()
{
	cin >> A >> B >> C;
	cout << solve(B) << endl;
}