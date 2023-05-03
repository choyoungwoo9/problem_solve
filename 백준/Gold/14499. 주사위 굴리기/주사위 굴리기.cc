#include <iostream>

using namespace std;

int N, M, x, y, K;

int my_map[20][20];

int dice[6];

int dice_index = 0;
//left right up down
int relation[4] = {2, 3, 4, 5};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void change_dice(int num)
{
	//right
	int tmp = dice_index;
	if(num == 1)
	{
		dice_index = relation[1];
		relation[0] = tmp;
		relation[1] = (tmp / 2) * 2 + (tmp + 1) % 2;
	}
	else if(num == 2)
	{
		dice_index = relation[0];
		relation[1] = tmp;
		relation[0] = (tmp / 2) * 2 + (tmp + 1) % 2;
	}
	else if(num == 3)
	{
		dice_index = relation[2];
		relation[3] = tmp;
		relation[2] = (tmp / 2) * 2 + (tmp + 1) % 2;
	}
	else
	{
		dice_index = relation[3];
		relation[2] = tmp;
		relation[3] = (tmp / 2) * 2 + (tmp + 1) % 2;
	}
	if(my_map[y][x] == 0)
	{
		my_map[y][x] = dice[dice_index];
	}
	else
	{
		dice[dice_index] = my_map[y][x];
		my_map[y][x] = 0;
	}
}


int main()
{
	cin >> N >> M >> y >> x >> K;
	for(int i = 0; i < N; i ++)
	{
		for(int j = 0; j < M; j ++)
		{
			cin >> my_map[i][j];
		}
	}
	for(int i = 0; i < K; i ++)
	{
		int num;
		cin >> num;
		if(dx[num-1] + x < 0 || dx[num-1] + x >= M)
			continue;
		if(dy[num-1] + y < 0 || dy[num-1] + y >= N)
			continue;
		x = dx[num-1] + x;
		y = dy[num-1] + y;
		change_dice(num);
		cout << dice[(dice_index / 2) * 2 + (dice_index + 1) % 2] << "\n";
	}
}