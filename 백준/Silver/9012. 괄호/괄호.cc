#include<iostream>
#include <string>
using namespace std;

int flag = 1;

int is_VPS(string &str)
{
	int cnt = 0;
	for(char ch : str)
	{
		if(ch == '(')
		{
			cnt ++;
		}
		else
		{
			cnt --;
			if(cnt < 0)
				return 0;
		}
	}
	if(cnt == 0)
		return 1;
	else
		return 0;
}

int main()
{
	int N;
	cin >> N;
	int cnt = 0;
	string tmp;
	getline(cin, tmp);
	for(int i = 0; i < N; i ++)
	{
		string str;
		getline(cin, str);
		if(is_VPS(str))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	
}