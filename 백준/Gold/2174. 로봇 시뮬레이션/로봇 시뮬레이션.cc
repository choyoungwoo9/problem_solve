#include <iostream>
#include <queue>
using namespace std;

int H, W;
int N, M;

int mp[101][101];

int robot_y[101];
int robot_x[101];
int robot_dir[101];

//event[i][0] : robot idx
//event[i][1] : order
//event[i][2] : repeat
int event[100][3];
//N E S W
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void rotate_left(int event_idx)
{
	int robot_idx = event[event_idx][0];
	int repeat = event[event_idx][2];
	repeat = repeat % 4;
	if(repeat > robot_dir[robot_idx])
		robot_dir[robot_idx] += 4;
	robot_dir[robot_idx] -= repeat;
}

void rotate_right(int event_idx)
{
	int robot_idx = event[event_idx][0];
	int repeat = event[event_idx][2];
	robot_dir[robot_idx] = (robot_dir[robot_idx] + repeat) % 4;
}

void crash_wall(int idx)
{
	cout << "Robot " << idx << " crashes into the wall" << endl;
	exit(0);
}

void crash_robot(int idx, int idx2)
{
	cout << "Robot " << idx << " crashes into robot " << idx2 << endl;
	exit(0);
}

void go(int event_idx)
{
	int robot_idx = event[event_idx][0];
	int repeat = event[event_idx][2];

	int dir = robot_dir[robot_idx];
	for(int i = 0; i < repeat; i ++)
	{
		int nx = robot_x[robot_idx] + dx[dir];
		int ny = robot_y[robot_idx] + dy[dir];
		if(ny <= 0 || ny > H || nx <= 0 || nx > W)
		{
			crash_wall(robot_idx);
		}
		else if(mp[ny][nx] != 0)
		{
			crash_robot(robot_idx, mp[ny][nx]);
		}
		mp[ny][nx] = robot_idx;
		mp[robot_y[robot_idx]][robot_x[robot_idx]] = 0;
		robot_y[robot_idx] = ny;
		robot_x[robot_idx] = nx;
	}
}

void event_loop()
{
	for(int i = 0; i < M; i ++)
	{
		if(event[i][1] == 'L')
		{
			rotate_left(i);
		}
		else if(event[i][1] == 'R')
		{
			rotate_right(i);
		}
		else if(event[i][1] == 'F')
		{
			go(i);
		}
	}
}

int main()
{
	cin >> W >> H;
	cin >> N >> M;
	for(int i = 1; i <= N; i ++)
	{
		int x, y;
		char dir;
		cin >> x >> y >> dir;
		mp[y][x] = i;
		robot_y[i] = y;
		robot_x[i] = x;
		if(dir == 'N')
			robot_dir[i] = 0;
		if(dir == 'E')
			robot_dir[i] = 1;
		if(dir == 'S')
			robot_dir[i] = 2;
		if(dir == 'W')
			robot_dir[i] = 3;
	}

	for(int i = 0; i < M; i ++)
	{
		int a, c;
		char b;
		cin >> a >> b >> c;
		event[i][0] = a;
		event[i][1] = b;
		event[i][2] = c;
	}
	event_loop();
	cout << "OK\n";
}