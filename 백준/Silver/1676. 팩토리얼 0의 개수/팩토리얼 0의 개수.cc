#include <iostream>

using namespace std;

int N;
int answer = 0;


int main()
{
	cin >> N;

	for(int i = 1; i <= N; i ++)
	{
		int num = i;
		while(num % 5 == 0)
		{
			num = num / 5;
			answer ++;
		}
	}
	cout << answer << endl;
}