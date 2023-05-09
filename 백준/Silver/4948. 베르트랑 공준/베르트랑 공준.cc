#include <iostream>

using namespace std;

int is_prime(int num)
{
	for(int i = 2; (unsigned long long)i*(unsigned long long)i <= (unsigned long long)num; i ++)
	{
		if(num%i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while(1)
	{
		int num;
		cin >> num;
		if(!num)
			return 0;
		int answer = 0;
		for(int i = num+1; i <= num*2; i ++)
		{
			if(is_prime(i))
				answer ++;
		}
		cout << answer << "\n";
	}
}