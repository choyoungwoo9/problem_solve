#include <iostream>

using namespace std;

bool is_used_ar[100][26];

int answer;

void check_str(int index, const string& str)
{
	char ch;
	for(int i = 0; i < str.length(); i ++)
	{
		char cur_ch = str.at(i);
		if(i == 0)
		{
			ch = cur_ch;
			is_used_ar[index][cur_ch - 'a'] = 1;
		}
		else if(ch != cur_ch)
		{
			if(is_used_ar[index][cur_ch - 'a'])
				return ;
			is_used_ar[index][cur_ch - 'a'] = 1;
			ch = cur_ch;
		}
	}
	answer ++;
}

int main()
{
	int N;
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		string str;
		cin >> str;
		string &r = str;
		check_str(i, r);
		//cout << answer << endl;
	}
	cout << answer << endl;
}