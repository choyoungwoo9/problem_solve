#include <iostream>

using namespace std;

char mp[64][65];

int N;

void func(int s_y, int s_x, int size)
{
	char value = mp[s_y][s_x];
	int flag = 1;
	for(int y = 0; y < size; y ++)
	{
		for(int x = 0; x < size; x ++)
		{
			if(mp[y+s_y][x+s_x] != value)
			{
				flag = 0;
				break;
			}
		}
		if(!flag)
				break;
	}
	if(flag)
	{
		cout << value;
	}
	else
	{
		cout << '(';
		func(s_y, s_x, size/2);
		func(s_y, s_x + size/2, size/2);
		func(s_y + size/2, s_x, size/2);
		func(s_y + size/2, s_x + size/2, size/2);
		cout << ')';
	}
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i ++)
		cin >> mp[i];
	func(0,0, N);
	cout << endl;
}