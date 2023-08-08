#include <iostream>
#include <string>

using namespace std;

string map[100];
string word;

int H, W;
int flag = 0;

int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};


void recursive_find(int y, int x, int dir, int cnt)
{
	if(cnt == word.size())
	{
		flag = 1;
		return ;
	}
	if(y < 0 || y >= H || x < 0 || x >= W)
		return ;
	if(map[y][x] != word[cnt])
		return ;
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	recursive_find(ny, nx, dir, cnt +1);
}

int main()
{
	cin >> word;
	cin >> H >> W;
	for(int i = 0; i < H; i++)
		cin >> map[i];
	for(int j = 0; j < H; j++)
	{
		for(int i = 0; i < W; i++)
		{
			for(int k = 0; k < 8; k++)
			{
				recursive_find(j, i, k, 0);
			}
		}
	}

	cout << flag << endl;
}