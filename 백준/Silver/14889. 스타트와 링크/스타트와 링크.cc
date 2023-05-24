#include <iostream>

using namespace std;

int input[20][20];
int N;
bool team[20];

int ans = -1;

int generate_value()
{
	int s_s = 0;
	int l_s = 0;
	for(int i = 0; i < N; i ++)
	{
		for(int j = 0; j < N; j ++)
		{
			if(team[i] == team[j] && team[i] == true)
				s_s += input[i][j];
			if(team[i] == team[j] && team[i] == false)
				l_s += input[i][j];
		}
	}
	return max(s_s, l_s) - min(s_s, l_s);
}

void recursive_find(int cnt, int cur_team, int start_team_count)
{
	if(cnt == N)
	{
		int tmp = generate_value();
		if(ans == -1 || ans > tmp)
			ans = tmp;
		return ;
	}
	if(cur_team == 1 && start_team_count < N / 2)
	{
		team[cnt] = true;
		recursive_find(cnt+1, 1, start_team_count+1);
		recursive_find(cnt+1, 0, start_team_count+1);
	}
	if(cur_team == 0 && (cnt-start_team_count) < N / 2)
	{
		team[cnt] = false;
		recursive_find(cnt+1, 1, start_team_count);
		recursive_find(cnt+1, 0, start_team_count);
	}
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		for(int j = 0; j < N; j ++)
			cin >> input[i][j];
	}
	recursive_find(0, 1, 0);
	recursive_find(0, 0, 0);
	cout << ans << endl;
}