#include <iostream>
#include <string>

using namespace std;

string str;

int main()
{
	cin >> str;
	int num = 0;
	int answer = 0;
	int flag = 0;
	for(int i = 0; i < str.size(); i ++)
	{
		if(str[i] == '-')
		{
			if(!flag)
			{
				answer = answer + num;
				num = 0;
			}
			else
			{
				answer = answer - num;
				num = 0;
			}	
			flag = 1;
		}
		else if(str[i] == '+')
		{
			if(!flag)
			{
				answer = answer + num;
				num = 0;
			}
			else
			{
				answer = answer - num;
				num = 0;
			}	
		}
		else
		{
			num = num * 10 + str[i] - '0';
		}
	}
	if(!flag)
		answer = answer + num;
	else
		answer = answer - num;
	cout << answer << endl;
}