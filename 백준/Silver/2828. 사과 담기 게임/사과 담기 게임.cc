#include <iostream>

using namespace std;

int N, M, J;

int s_x = 1;
int answer = 0;

int main()
{
	cin >> N >> M >> J;
	for(int i = 0; i < J; i ++)
	{
		int x;
		cin >> x;
		if(s_x <= x && s_x + M - 1 >= x)
		{
			continue;
		}
		else if(x < s_x)
		{
			answer += s_x - x;
			s_x -= s_x - x;
		}
		else if(x > s_x + M -1)
		{
			answer += x - (s_x+M-1);
			s_x += x - (s_x+M-1);
		}
	}
	cout << answer << endl;
}