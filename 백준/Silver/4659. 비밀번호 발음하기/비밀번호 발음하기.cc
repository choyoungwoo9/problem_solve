#include <iostream>
#include <string>
using namespace std;

string str;
string input;
int flag1;
int flag2;
int flag3;

void solve()
{
	flag1 = 0;
	flag2 = 1;
	flag3 = 1;

	for(char ch : input)
	{
		if(str.find(ch) != string::npos)
		{
			flag1 = 1;
		}
	}

	int cnt = 0;
	int team = -1;
	for(int i = 0; i < input.size(); i ++)
	{
		int cur_team;
		if(str.find(input[i]) != string::npos)
			cur_team = 1;
		else
			cur_team = 2;
		if(i == 0)
		{
			team = cur_team;
			continue;
		}
		if(team == cur_team)
			cnt ++;
		else
		{
			cnt = 0;
			team = cur_team;
		}
		if(cnt >= 2)
			flag2 = 0;
	}

	char b_ch = 'A';
	for(char ch : input)
	{
		if(b_ch == ch)
		{
			if(ch == 'e' || ch == 'o')
				continue;
			else
				flag3 = 0;
		}
		else
			b_ch = ch;
	}

	cout << "<" << input << "> ";

	if(flag1 && flag2 && flag3)
	{
		cout << "is acceptable.\n";
	}
	else
		cout << "is not acceptable.\n";
}

int main()
{
	str = "aeiou";
	while(1)
	{
		cin >> input;
		if(input == "end")
			break;
		solve();
	}
}