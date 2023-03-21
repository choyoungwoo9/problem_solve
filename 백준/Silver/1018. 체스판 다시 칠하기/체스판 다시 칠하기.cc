#include <iostream>

using namespace std;

int N, M;

char map[50][51];

int black_start, white_start;
int answer = -1;
int my_min(int a, int b)
{
	if(a > b)
		return b;
	return a;
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i < N; i ++)
	{
		cin >> map[i];
	}
	for(int y = 0; y <= N-8; y ++)
	{
		for(int x = 0; x <= M-8; x ++)
		{
			//cout << x << " " << y << endl;
			for(int i = 0; i < 8; i ++)
			{
				for(int j = 0; j < 8; j ++)
				{
					if((i+j) % 2 == 0)
					{
						if(map[y+i][x+j] == 'W')
							black_start ++;
						else
							white_start ++;
					}
					else
					{
						if(map[y+i][x+j] == 'B')
							black_start ++;
						else
							white_start ++;
					}
				}
			}
			//cout << black_start << " " << white_start << endl;
			if(answer < 0 || answer > my_min(black_start, white_start))
				answer = my_min(black_start, white_start);
			black_start = 0;
			white_start = 0;
		}
	}
	cout << answer << endl;
}