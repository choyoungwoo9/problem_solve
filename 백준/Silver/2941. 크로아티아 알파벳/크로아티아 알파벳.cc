#include <iostream>

using namespace std;

int answer;

int main()
{
	string str;
	cin >> str;
	int i = 0;
	while(i < str.size())
	{
		if(str[i] == 'c')
		{
			if(i + 1 < str.size() && str[i+1] == '=')
			{
				i += 2;
			}
			else if(i + 1 < str.size() && str[i+1] == '-')
			{
				i += 2;
			}
			else
			{
				i ++;
			}
		}
		else if(str[i] == 'd')
		{
			if(i + 1 < str.size() && str[i+1] == '-')
			{
				i += 2;
			}
			else if(i + 2 < str.size() && str[i+1] == 'z' && str[i+2] == '=')
			{
				i+= 3;
			}
			else
				i ++;
		}
		else if(str[i] == 'l')
		{
			if(i + 1 < str.size() && str[i+1] == 'j')
				i += 2;
			else
				i ++;
		}
		else if(str[i] == 'n')
		{
			if(i + 1 < str.size() && str[i+1] == 'j')
				i += 2;
			else
				i ++;
		}
		else if(str[i] == 's')
		{
			if(i + 1 < str.size() && str[i+1] == '=')
				i += 2;
			else
				i ++;
		}
		else if(str[i] == 'z')
		{
			if(i + 1 < str.size() && str[i+1] == '=')
				i += 2;
			else
				i ++;
		}
		else
		{
			i++;
		}
		answer ++;
	}
	cout << answer << endl;
}