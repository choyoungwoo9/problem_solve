#include <iostream>
#include <vector>

using namespace std;
int N, M;

int answer = 0;
int cur = 0;

int main()
{
	cin >> N >> M;
	for(int i = 0; i < N; i ++)
	{
		int num;
		cin >> num;
		if(cur + num > M)
		{
			answer ++;
			cur = num;
		}
		else
		{
			cur += num;
		}
	}
	if(cur)
		answer ++;
	cout << answer << endl;
}