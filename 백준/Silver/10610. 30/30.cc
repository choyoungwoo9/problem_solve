#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;
int flag = 0;
int sum = 0;

int cmp(char a, char b)
{
	return a > b;
}

int main()
{
	cin >> str;
	for(int i = 0; i < str.size(); i ++)
	{
		if(str[i] == '0')
			flag = 1;
		sum += str[i] - '0';
	}
	if(sum % 3 == 0 && flag)
	{
		sort(str.begin(), str.end(), cmp);
		cout << str << endl;
	}
	else
	{
		cout << "-1" << endl;
	}
}