#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mp[8][8];
int mp_tmp[8][8];
int H, W;
vector<int> cctv;

int answer = 64;

void f_up(int y, int x)
{
	for(int ny = y+1; ny < H; ny ++)
	{
		if(mp_tmp[ny][x] == 6)
			break;
		mp_tmp[ny][x] = 7;
	}
}

void f_down(int y, int x)
{
	for(int ny = y-1; ny >= 0; ny --)
	{
		if(mp_tmp[ny][x] == 6)
			break;
		mp_tmp[ny][x] = 7;
	}
}

void f_right(int y, int x)
{
	for(int nx = x+1; nx < W; nx ++)
	{
		if(mp_tmp[y][nx] == 6)
			break;
		mp_tmp[y][nx] = 7;
	}
}

void f_left(int y, int x)
{
	for(int nx = x-1; nx >= 0; nx --)
	{
		if(mp_tmp[y][nx] == 6)
			break;
		mp_tmp[y][nx] = 7;
	}
}

void find_answer()
{
	int tmp_ans = 0;
	for(int j = 0; j < H; j ++)
	{
		for(int i = 0; i < W; i ++)
		{
			if(mp_tmp[j][i] == 0)
				tmp_ans ++;
		}
	}
	answer = min(answer, tmp_ans);
	for(int j = 0; j < H; j ++)
		for(int i = 0; i < W; i ++)
			mp_tmp[j][i] = mp[j][i];
}

int type[8];

void set_cctv1(int y, int x, int cctv_dir)
{
	if(cctv_dir == 1)
	{
		f_up(y, x);
	}
	else if(cctv_dir == 2)
	{
		f_down(y, x);
	}
	if(cctv_dir == 3)
	{
		f_right(y, x);
	}
	else if(cctv_dir == 4)
	{
		f_left(y, x);
	}
}

void set_cctv2(int y, int x, int cctv_dir)
{
	if(cctv_dir == 3 || cctv_dir == 4)
		return ;
	if(cctv_dir == 1)
	{
		f_up(y, x);
		f_down(y, x);
	}
	else if(cctv_dir == 2)
	{
		f_right(y, x);
		f_left(y, x);
	}
}

void set_cctv3(int y, int x, int cctv_dir)
{
	if(cctv_dir == 1)
	{
		f_up(y, x);
		f_right(y, x);
	}
	else if(cctv_dir == 2)
	{
		f_up(y, x);
		f_left(y, x);
	}
	if(cctv_dir == 3)
	{
		f_down(y, x);
		f_left(y, x);
	}
	else if(cctv_dir == 4)
	{
		f_down(y, x);
		f_right(y, x);
	}
}

void set_cctv4(int y, int x, int cctv_dir)
{
	if(cctv_dir == 1)
	{
		f_up(y, x);
		f_down(y, x);
		f_right(y, x);
	}
	else if(cctv_dir == 2)
	{
		f_up(y, x);
		f_down(y, x);
		f_left(y, x);
	}
	if(cctv_dir == 3)
	{
		f_down(y, x);
		f_right(y, x);
		f_left(y, x);
	}
	else if(cctv_dir == 4)
	{
		f_up(y, x);
		f_right(y, x);
		f_left(y, x);
	}
}

void set_cctv5(int y, int x, int cctv_dir)
{
	f_down(y, x);
	f_up(y, x);
	f_right(y, x);
	f_left(y, x);
}

void set_tmp_mp()
{
	for(int k = 0; k < cctv.size(); k ++)
	{
		int y = cctv[k]/8;
		int x = cctv[k]%8;
		int cctv_type = mp[y][x];
		int cctv_dir = type[k];
		if(cctv_type == 1)
			set_cctv1(y, x, cctv_dir);
		if(cctv_type == 2)
			set_cctv2(y, x, cctv_dir);
		if(cctv_type == 3)
			set_cctv3(y, x, cctv_dir);
		if(cctv_type == 4)
			set_cctv4(y, x, cctv_dir);
		if(cctv_type == 5)
			set_cctv5(y, x, cctv_dir);
	}
}

void go(int idx)
{
	if(idx == cctv.size())
	{
		set_tmp_mp();
		find_answer();
		return ;
	}
	for(int i = 1; i <= 4; i ++)
	{
		type[idx] = i;
		go(idx+1);
	}
}

//no cctv case think !!
int main()
{
	cin >> H >> W;
	for(int j = 0; j< H; j++)
		for(int i = 0; i < W; i++)
		{
			cin >> mp[j][i];
			if(mp[j][i] >= 1 && mp[j][i] <= 5)
			{
				cctv.push_back(j*8+i);
			}
		}
	for(int j = 0; j < H; j ++)
		for(int i = 0; i < W; i ++)
			mp_tmp[j][i] = mp[j][i];
	find_answer();
	go(0);
	cout << answer << endl;
}