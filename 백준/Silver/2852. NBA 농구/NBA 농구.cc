#include <iostream>

using namespace std;

int before_time = 0;

int s1;
int s2;

int t1;
int t2;

void make_tt(int t)
{
	if(t < 10)
		cout << 0;
	cout << t;
}

int main()
{
	int T;
	cin >> T;
	for(int i = 0; i < T; i ++)
	{
		int team, h, m;
		scanf("%d %d:%d", &team, &h, &m);
		int cur_m = h*60 + m;
		if(s1 > s2)
			t1 += cur_m - before_time;
		else if(s2 > s1)
			t2 += cur_m - before_time;
		if(team == 1)
			s1 ++;
		else
			s2 ++;
		before_time = cur_m;
	}
	if(s1 > s2)
		t1 += 48 * 60 - before_time;
	else if(s2 > s1)
		t2 += 48 * 60 - before_time;
	make_tt(t1 / 60);
	cout << ":";
	make_tt(t1 % 60);
	cout << '\n';

	make_tt(t2 / 60);
	cout << ":";
	make_tt(t2 % 60);
	cout << '\n';
}