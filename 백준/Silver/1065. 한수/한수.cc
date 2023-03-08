#include <iostream>
using namespace std;

int N;
int answer;

int is_hansoo(int num)
{
	int gap = 100;
	while(num)
	{
		if(num < 10)
			break ;
		int first = num % 10;
		int second = (num % 100) / 10;
		if(gap == 100)
			gap = first - second;
		if(gap != first - second)
			return 0;
		num /= 10;
	}
	return 1;
}

int main()
{
	cin >> N;
	for(int i = 1; i <= N; i ++)
	{
		if(is_hansoo(i))
			answer ++;
	}
	cout << answer << endl;
}