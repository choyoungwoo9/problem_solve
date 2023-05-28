#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >>str;
	sort(str.begin(), str.end());
	string s_str;
	string m_str;
	int flag = 1;
	for(int i = 0; i < str.size(); i ++)
	{
		if(i+1 == str.size())
		{
			if(m_str != "" || str.size() % 2 == 0)
			{
				cout << "I'm Sorry Hansoo" << endl;
				return 0;
			}
			m_str = str[i];
			break;
		}
		if(str[i] == str[i+1])
		{
			s_str += str[i];
			i ++;
		}
		else
		{
			if(m_str != "" || str.size() % 2 == 0)
			{
				cout << "I'm Sorry Hansoo" << endl;
				return 0;
			}
			m_str = str[i];
		}
	}
	string d_str = s_str;
	reverse(d_str.begin(), d_str.end());
	cout << s_str+m_str+d_str << endl;
}