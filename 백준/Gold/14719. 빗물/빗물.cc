#include <iostream>

using namespace std;

int mp[500][500];

int H, W;

int answer = 0;

void check(int y, int x)
{
	int flag1 = 0;
	int flag2 = 0;
	for(int i = 0; i < W; i ++)
	{
		if(i < x && mp[y][i])
			flag1 = 1;
		else if(i == x && flag1 == 0)
			return ;
		else if(i > x && mp[y][i])
			flag2 = 1;
	}
	if(flag2)
		answer ++;
}

int main()
{
	cin >> H >> W;
	for(int i = 0; i < W; i ++)
	{
		int num;
		cin >> num;
		for(int j = 0; j < num; j ++)
			mp[j][i] = 1;
	}

	
	for(int j = 0; j < H; j ++)
	{
		for(int i = 0; i < W; i ++)
		{
			if(mp[j][i] == 1)
				continue;
			check(j, i);
		}
	}
	cout << answer << endl;
}