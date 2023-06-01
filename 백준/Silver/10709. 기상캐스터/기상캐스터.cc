#include <iostream>

using namespace std;

int H, W;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> H >> W;
	for(int j = 0; j < H; j ++)
	{
		int flag = -1;
		for(int i = 0; i < W; i ++)
		{
			char ch;
			cin >> ch;
			if(ch == 'c')
			{
				flag = 0;
				cout << "0 ";
			}
			else
			{
				if(flag == -1)
				{
					cout << "-1 ";
				}
				else
				{
					flag ++;
					cout << flag << " ";
				}
			}
		}
		cout << "\n";
	}
}