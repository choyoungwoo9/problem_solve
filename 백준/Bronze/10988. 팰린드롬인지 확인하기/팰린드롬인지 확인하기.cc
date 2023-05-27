#include <iostream>
#include <string>

using namespace std;

string str;

int main()
{
	cin >> str;
	int flag = 1;
	for(int i = 0; i < str.size(); i ++)
	{
		if(str[i] != str[str.size()-i-1])
		{
			flag = 0;
			break;
		}
	}

	cout << flag << endl;
}