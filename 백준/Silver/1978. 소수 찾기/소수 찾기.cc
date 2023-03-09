#include <iostream>
using namespace std;
int is_prime(int num)
{
	if(num < 2)
		return 0;
	for(int i = 2; i * i <= num; i ++)
	{
		if(num % i == 0)
			return 0;
	}
	return 1;
}

int answer;

int main()
{
	int N;
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		int tmp;
		cin >> tmp;
		if(is_prime(tmp))
			answer ++;
	}
	cout << answer << endl;
}