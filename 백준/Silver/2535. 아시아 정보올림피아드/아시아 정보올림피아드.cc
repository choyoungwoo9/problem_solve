#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct p{
	int team;
	int num;
	int score;
} p;

vector<p> vt;

bool compare(p &a, p &b)
{
	return a.score > b.score;
}

int main()
{	
	int N;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		p pl;
		cin >> pl.team >> pl.num >> pl.score;
		vt.push_back(pl);
	}
	sort(vt.begin(), vt.end(), compare);

	cout << vt[0].team << " " << vt[0].num << "\n";
	cout << vt[1].team << " " << vt[1].num << "\n";

	int flag = 0;
	int fTeam;
	if(vt[0].team == vt[1].team)
	{
		flag = 1;
		fTeam = vt[0].team;
	}

	if(!flag)
	{
		cout << vt[2].team << " " << vt[2].num << "\n";
		return 0;
	}
	for(int i = 2; i < vt.size(); i++)
	{
		if(vt[i].team != fTeam)
		{
			cout << vt[i].team << " " << vt[i].num << "\n";
			return 0;
		}
	}
}