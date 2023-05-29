#include <iostream>

using namespace std;

void solution(int num)
{
	int tmp = 1;
	int cnt = 1;
	while(1)
	{
		if(num <= tmp)
			break;
		tmp = tmp * 10 + 1;
		cnt ++;
	}
	while(1)
	{
		tmp = tmp % num;
		if(tmp == 0)
			break;
		tmp = tmp * 10 + 1;
		cnt ++;
	}
	cout << cnt << "\n";
}

int main()
{
	int n;
	while(cin >> n)
	{
		// cin >> n;
		solution(n);
	}
}