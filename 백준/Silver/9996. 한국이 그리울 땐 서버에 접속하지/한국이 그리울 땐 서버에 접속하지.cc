#include <iostream>

using namespace std;

int N;
string pt;

int main()
{
	cin >> N;
	cin >> pt;
	for(int i = 0 ; i < N; i ++)
	{
		string str;
		cin >> str;
		int flag = 1;
		if(str.size() < pt.size()-1)
			flag = 0;
		if(!flag)
		{
			cout << "NE\n";
			continue;
		}
		int idx = 0;
		while(1)
		{
			if(pt[idx] == '*')
				break;
			if(pt[idx] != str[idx])
			{
				flag = 0;
				break;
			}
			idx ++;
		}
		if(!flag)
		{
			cout << "NE\n";
			continue;
		}
		idx = 1;
		while(1)
		{
			if(pt[pt.size()-idx] == '*')
				break;
			if(pt[pt.size()-idx] != str[str.size()-idx])
			{
				flag = 0;
				break;
			}
			idx ++;
		}
		if(!flag)
		{
			cout << "NE\n";
			continue;
		}
		cout << "DA\n";
	}
}